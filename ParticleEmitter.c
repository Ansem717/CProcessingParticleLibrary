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
		.mode = PE_MODE_DIRECTIONAL,
		.size = 10,
		.speed = 5,
		.lifespan = 100,
		.weight = 0.1,
		.col = CP_Color_Create(0,0,0,255)
	};
	return pe;
}

void PE_Emitter_SetPosition(ParticleEmitter* pe, CP_Vector position) { pe->position = position; }
void PE_Emitter_SetMode(ParticleEmitter* pe, PE_MODE mode) { pe->mode = mode; }
void PE_Emitter_SetAngle(ParticleEmitter* pe, float theta) { pe->directionalAngle = theta; }
void PE_Emitter_SetAngleRange(ParticleEmitter* pe, float thetaRange) { pe->directionalRange = thetaRange; }

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

Particle removeParticleFromFront(ParticleEmitter* pe, int index) {
	for (int j = index; j > 0; j--) {
		//J will start at given index, ex: 4... [z x c v b n m] starts at [z x c v (b) n m]
		//pe[4] becomes pe[3]. So the array is now [z x c v v n m]
		//Keep going: zxccvnm -> zxxcvnm -> zzxcvnm; then when you run DEQEUE below: zxcvnm_
		pe->particles[j] = pe->particles[j - 1];
	}
}

void PE_Particle_Add(ParticleEmitter* pe) {
	float theta = getRandomTheta(180, 180); //RADIAL is between 0 and 360
	if (pe->mode == PE_MODE_DIRECTIONAL) {
		theta = getRandomTheta(pe->directionalAngle, pe->directionalRange);
	}
	pe->particles[pe->count] = newParticle(
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
	pe->count += 1;
	pe->count %= 50;
}

void PE_Emitter_Run(ParticleEmitter* pe) {
	for (int i = 0; i < 50; i++) {
		pe->particles[i].position = CP_Vector_Add(pe->particles[i].position, pe->particles[i].speed);
		pe->particles[i].speed = CP_Vector_Add(pe->particles[i].acceleration, pe->particles[i].speed);
		pe->particles[i].acceleration.y += pe->particles[i].weight;
		draw(pe->particles[i]);
		if (pe->particles[i].lifespan <= 0) {

		}
	}
}
