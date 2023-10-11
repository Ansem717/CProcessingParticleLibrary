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
	pe.maxCount = 50;
	pe.fadeout = PE_EFFECT_FADEOUT;
	pe.size = 10;
	pe.speed = 10;
	pe.lifespan = 100;
	return pe;
}

void PE_Emitter_SetPosition(ParticleEmitter* pe, CP_Vector position) { pe->position = position; }
void PE_Emitter_SetMode(ParticleEmitter* pe, PE_MODE mode) { pe->mode = mode; }
void PE_Emitter_SetAngle(ParticleEmitter* pe, float theta) { pe->directionalAngle = theta; }
void PE_Emitter_SetAngleRange(ParticleEmitter* pe, float thetaRange) { pe->directionalRange = thetaRange; }
void PE_Emitter_SetMaxParticles(ParticleEmitter* pe, int maxCount) { pe->maxCount = maxCount; }
void PE_Emitter_SetFadeout(ParticleEmitter* pe, PE_EFFECT effect) { pe->fadeout = effect; }
void PE_Emitter_SetFlash(ParticleEmitter* pe, PE_EFFECT effect) { pe->flash = effect; }
void PE_Emitter_SetSpin(ParticleEmitter* pe, PE_EFFECT effect) { pe->spin = effect; }
void PE_Emitter_SetShrink(ParticleEmitter* pe, PE_EFFECT effect) { pe->shrink = effect; }
void PE_Emitter_SetGrow(ParticleEmitter* pe, PE_EFFECT effect) { pe->grow = effect; }
void PE_Particle_SetSize(ParticleEmitter* pe, float size) { pe->size = size; }
void PE_Particle_SetShape(ParticleEmitter* pe, PE_SHAPE shape) { pe->shape = shape; }
void PE_Particle_SetSpeed(ParticleEmitter* pe, float speed) { pe->speed = speed; }
void PE_Particle_SetAcceleration(ParticleEmitter* pe, float acceleration) { pe->acceleration = acceleration; }
void PE_Particle_SetWeight(ParticleEmitter* pe, float weight) { pe->weight = weight; }
void PE_Particle_SetLifespan(ParticleEmitter* pe, int lifespan) { pe->lifespan = lifespan; }

void PE_Particle_Add(ParticleEmitter* pe) {
    
}

void PE_Emitter_Run(ParticleEmitter* pe) {
    
}
