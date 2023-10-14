//---------------------------------------------------------
// file:	particleSystem.c
// author:	Andy Malik
// email:	andy.malik@digipen.edu
//
// brief:	System functions to manage Particles
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------

#include "ParticleEmitter.h"
#include <stdio.h>
#include <stdlib.h>

ParticleEmitter PE_Emitter_New(CP_Vector position) {
	ParticleEmitter pe = {
		.position = position,
		.targetMode = PE_TARGET_MODE_DIRECTIONAL,
		.size = 10,
		.speed = 5,
		.lifespan = 100,
		.weight = 0.1,
		.col = CP_Color_Create(0,0,0,255),
		.delayMode = PE_DELAY_MODE_FRAMES
	};
	return pe;
}

void PE_Emitter_SetPosition(ParticleEmitter* pe, CP_Vector position) { pe->position = position; }
void PE_Emitter_SetTargetMode(ParticleEmitter* pe, PE_TARGET_MODE mode) { pe->targetMode = mode; }
void PE_Emitter_SetAngle(ParticleEmitter* pe, float theta) { pe->directionalAngle = theta; }
void PE_Emitter_SetAngleRange(ParticleEmitter* pe, float thetaRange) { pe->directionalRange = thetaRange; }

void PE_Emitter_SetDelaySeconds(ParticleEmitter* pe, float delaySeconds) { pe->delaySeconds = delaySeconds; }
void PE_Emitter_SetDelayFrames(ParticleEmitter* pe, int delayFrames) { pe->delayFrames = delayFrames; }
void PE_Emitter_SetDelayMode(ParticleEmitter* pe, PE_DELAY_MODE mode) { pe->delayMode = mode; }

void PE_Effect_AddEffect(ParticleEmitter* pe, PE_EFFECT effect) { pe->effects[effect] = 1; }
void PE_Effect_RemoveEffect(ParticleEmitter* pe, PE_EFFECT effect) { pe->effects[effect] = 0; }
void PE_Effect_ClearEffects(ParticleEmitter* pe) { memset(pe->effects, 0, sizeof(pe->effects)); }

void PE_Particle_SetSize(ParticleEmitter* pe, float size) { pe->size = size; }
void PE_Particle_SetShape(ParticleEmitter* pe, PE_SHAPE shape) { pe->shape = shape; }
void PE_Partcile_SetColorRandom(ParticleEmitter* pe) { pe->col = CP_Color_FromColorHSL(CP_ColorHSL_Create(CP_Random_RangeInt(0, 255), 255, 255, 255)); }
void PE_Particle_SetColor(ParticleEmitter* pe, CP_Color color) { pe->col = color; }
void PE_Particle_SetSpeed(ParticleEmitter* pe, float speed) { pe->speed = speed; }
void PE_Particle_SetAcceleration(ParticleEmitter* pe, float acceleration) { pe->acceleration = acceleration; }
void PE_Particle_SetWeight(ParticleEmitter* pe, float weight) { pe->weight = weight; }
void PE_Particle_SetLifespan(ParticleEmitter* pe, int lifespan) { pe->lifespan = lifespan; }

float getRandomTheta(float origin, float range) {
	return CP_Random_RangeFloat(origin - range, origin + range);
}

void removeParticleFromFront(ParticleEmitter* pe, int index) {
	for (int j = index; j > 0; j--) {
		//J will start at given index, ex: 4... [z x c v b n m] starts at [z x c v (b) n m]
		//pe[4] becomes pe[3]. So the array is now [z x c v v n m]
		//Keep going: zxccvnm -> zxxcvnm -> zzxcvnm; then when you run DEQEUE below: zxcvnm_
		pe->particles[j] = pe->particles[j - 1];
	}
}

void dequeue(ParticleEmitter *pe) {
	pe->head++;
	pe->count--;
}

void PE_Particle_Add(ParticleEmitter* pe) {

	if (pe->delayMode == PE_DELAY_MODE_FRAMES) {
		if (CP_System_GetFrameCount() < pe->_delayTimestamp + pe->delayFrames) return;
	} else if (CP_System_GetSeconds() < pe->_delayTimestamp + pe->delaySeconds) return;

	float theta = getRandomTheta(180, 180); //RADIAL is between 0 and 360
	if (pe->targetMode == PE_TARGET_MODE_DIRECTIONAL) {
		theta = getRandomTheta(pe->directionalAngle, pe->directionalRange);
	}
	pe->particles[pe->tail] = newParticle(
		pe->position,
		pe->speed,
		pe->acceleration,
		pe->size,
		theta,
		pe->weight,
		pe->lifespan,
		pe->shape,
		pe->col
	);
	pe->count++;
	if (pe->count > PE_PARTICLE_ARR_SIZE) pe->count = PE_PARTICLE_ARR_SIZE;
	pe->tail++;
	pe->tail %= PE_PARTICLE_ARR_SIZE;
	if (pe->delayMode == PE_DELAY_MODE_FRAMES) pe->_delayTimestamp = CP_System_GetFrameCount();
	else pe->_delayTimestamp = CP_System_GetSeconds();
}

void PE_Emitter_Run(ParticleEmitter* pe) {
	for (int i = pe->head; i < pe->count + pe->head; i++) {
		int index = i % PE_PARTICLE_ARR_SIZE;
		pe->particles[index].position = CP_Vector_Add(pe->particles[index].position, pe->particles[index].speed);
		pe->particles[index].speed = CP_Vector_Add(pe->particles[index].acceleration, pe->particles[index].speed);
		pe->particles[index].acceleration.y += pe->particles[index].weight;
		draw(pe->particles[index]);
		pe->particles[index].lifespan--;
		if (pe->particles[index].lifespan <= 0) {
			dequeue(pe);
		}
	}
}
