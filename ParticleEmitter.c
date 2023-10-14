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

ParticleEmitter PE_New(CP_Vector position) {
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

void PE_SetPosition(ParticleEmitter* pe, CP_Vector position) { pe->position = position; }
void PE_SetTargetMode(ParticleEmitter* pe, PE_TARGET_MODE mode) { pe->targetMode = mode; }
void PE_SetAngle(ParticleEmitter* pe, float theta) { pe->directionalAngle = theta; }
void PE_SetAngleRange(ParticleEmitter* pe, float thetaRange) { pe->directionalRange = thetaRange; }

void PE_SetDelaySeconds(ParticleEmitter* pe, float delaySeconds) { pe->delaySeconds = delaySeconds; }
void PE_SetDelayFrames(ParticleEmitter* pe, int delayFrames) { pe->delayFrames = delayFrames; }
void PE_SetDelayMode(ParticleEmitter* pe, PE_DELAY_MODE mode) { pe->delayMode = mode; }

void PE_AddEffect(ParticleEmitter* pe, PE_EFFECT effect, int value) { pe->effects[effect] = value; }
void PE_RemoveEffect(ParticleEmitter* pe, PE_EFFECT effect) { pe->effects[effect] = 0; }
void PE_ClearEffects(ParticleEmitter* pe) { memset(pe->effects, 0, sizeof(pe->effects)); }

void PE_SetSize(ParticleEmitter* pe, float size) { pe->size = size; }
void PE_SetShape(ParticleEmitter* pe, PE_SHAPE shape) { pe->shape = shape; }

void PE_SetColorRandom(ParticleEmitter* pe) {
	pe->col = CP_Color_FromColorHSL(
		CP_ColorHSL_Create(
			CP_Random_RangeInt(0, 360),
			100,
			80,
			255
		)
	);
}

void PE_SetColor(ParticleEmitter* pe, CP_Color color) { pe->col = color; }
void PE_SetSpeed(ParticleEmitter* pe, float speed) { pe->speed = speed; }
void PE_SetAcceleration(ParticleEmitter* pe, float acceleration) { pe->acceleration = acceleration; }
void PE_SetWeight(ParticleEmitter* pe, float weight) { pe->weight = weight; }
void PE_SetLifespan(ParticleEmitter* pe, int lifespan) { pe->lifespan = lifespan; }

float getRandomTheta(float origin, float range) {
	return CP_Random_RangeFloat(origin - range, origin + range);
}

void dequeue(ParticleEmitter* pe) {
	pe->head++;
	pe->count--;
}

void enqueue(ParticleEmitter* pe) {
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
}

void PE_AddMany(ParticleEmitter* pe, int amount) {
	if (pe->delayMode == PE_DELAY_MODE_FRAMES) {
		if (CP_System_GetFrameCount() < pe->_delayTimestamp + pe->delayFrames) return;
	} else if (CP_System_GetSeconds() < pe->_delayTimestamp + pe->delaySeconds) return;

	for (int i = 0; i < amount; i++) {
		enqueue(pe);
	}

	if (pe->delayMode == PE_DELAY_MODE_FRAMES) pe->_delayTimestamp = CP_System_GetFrameCount();
	else pe->_delayTimestamp = CP_System_GetSeconds();
}

void PE_Add(ParticleEmitter* pe) {
	if (pe->delayMode == PE_DELAY_MODE_FRAMES) {
		if (CP_System_GetFrameCount() < pe->_delayTimestamp + pe->delayFrames) return;
	} else if (CP_System_GetSeconds() < pe->_delayTimestamp + pe->delaySeconds) return;

	enqueue(pe);

	if (pe->delayMode == PE_DELAY_MODE_FRAMES) pe->_delayTimestamp = CP_System_GetFrameCount();
	else pe->_delayTimestamp = CP_System_GetSeconds();
}

void PE_Run(ParticleEmitter* pe) {
	for (int i = pe->head; i < pe->count + pe->head; i++) {
		int index = i % PE_PARTICLE_ARR_SIZE;
		pe->particles[index].position = CP_Vector_Add(pe->particles[index].position, pe->particles[index].speed);
		pe->particles[index].speed = CP_Vector_Add(pe->particles[index].acceleration, pe->particles[index].speed);
		pe->particles[index].acceleration.y += pe->particles[index].weight;

		pe->particles[index].color.a -= pe->effects[PE_EFFECT_FADEOUT];
		if (pe->particles[index].color.a <= 0) pe->particles[index].color.a = 0;

		draw(pe->particles[index]);


		pe->particles[index].lifespan--;
		if (pe->particles[index].lifespan <= 0) {
			dequeue(pe);
		}
	}
}
