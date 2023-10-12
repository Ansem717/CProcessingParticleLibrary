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

ParticleEmitter PE_Emitter_New(CP_Vector position) {
	ParticleEmitter pe = { 0 };
	//Set Defaults
	pe.position = position;
	pe.mode = PE_MODE_RADIAL;
	pe.size = 10;
	pe.speed = 10;
	pe.lifespan = 100;
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
void PE_Particle_SetColor(ParticleEmitter* pe, CP_Color color) { pe->color = color; }
void PE_Particle_SetSpeed(ParticleEmitter* pe, float speed) { pe->speed = speed; }
void PE_Particle_SetAcceleration(ParticleEmitter* pe, float acceleration) { pe->acceleration = acceleration; }
void PE_Particle_SetWeight(ParticleEmitter* pe, float weight) { pe->weight = weight; }
void PE_Particle_SetLifespan(ParticleEmitter* pe, int lifespan) { pe->lifespan = lifespan; }

void PE_Particle_Add(ParticleEmitter* pe) {
	if (pe->count == 50) return; // We have 50 particles. We can't add more. We must wait for one to die naturally.
	//pe->particles[pe->count] = newParticle(); 
	pe->count += 1;
}

void PE_Emitter_Run(ParticleEmitter* pe) {
    
}
