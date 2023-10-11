//---------------------------------------------------------
// file:	ParticleEmitter.h
// author:	Andy Malik
// email:	andy.malik@digipen.edu
//
// brief:	Header for Particle system
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------

#ifndef PARTICLE_EMITTER_H
#define PARTICLE_EMITTER_H

#include "cprocessing.h"
#include "particle.h"

typedef enum PE_MODE {
	PE_MODE_DIRECTIONAL,
	PE_MODE_RADIAL
} PE_MODE ;

typedef enum PE_EFFECT {
	PE_EFFECT_NONE,
	PE_EFFECT_FADEOUT,
	PE_EFFECT_FLASH,
	PE_EFFECT_SPIN,
	PE_EFFECT_SHRINK,
	PE_EFFECT_GROW
} PE_EFFECT ;

typedef enum PE_SHAPE {
	PE_SHAPE_CIRCLE,
	PE_SHAPE_SQUARE
} PE_SHAPE;

typedef struct ParticleEmitter {
	CP_Vector position;
	PE_MODE mode; //PE_MODE_DIRECTIONAL emits the particles in a specific direction; PE_MODE_RADIAL emits the particles in a random circle.
	float directionalAngle; //0 degrees is north
	float directionalRange; //0 means all particles have no randomness when spawned.
	int maxCount; //Maximum number of particles; LIMIT IS 50.
	PE_EFFECT fadeout; //PE_EFFECT uses the enum as a boolean mock. Check if NONE or not.
	PE_EFFECT flash; //PE_EFFECT uses the enum as a boolean mock. Check if NONE or not.
	PE_EFFECT spin; //PE_EFFECT uses the enum as a boolean mock. Check if NONE or not.
	PE_EFFECT shrink; //PE_EFFECT uses the enum as a boolean mock. Check if NONE or not.
	PE_EFFECT grow; //PE_EFFECT uses the enum as a boolean mock. Check if NONE or not.

	float size; //Initial size of particle
	PE_SHAPE shape; //Shape of each particle.
	float speed; //Initial speed of particle.
	float acceleration; //Gain (or negative for Loss) of speed over time.
	float weight; //Higher weight, the more relevant gravity; Weight = 0 means no fall. 
	int lifespan; //Number of frames the particle will exist
	Particle particles[50]; //Particle Array
} ParticleEmitter;

ParticleEmitter PE_Emitter_New(CP_Vector position);

void PE_Emitter_SetPosition(ParticleEmitter pe, CP_Vector position);
void PE_Emitter_SetMode(ParticleEmitter pe, PE_MODE mode);
void PE_Emitter_SetAngle(ParticleEmitter pe, float theta);
void PE_Emitter_SetAngleRange(ParticleEmitter pe, float thetaRange);
void PE_Emitter_SetMaxParticles(ParticleEmitter pe, int maxCount);
void PE_Emitter_SetFadeout(ParticleEmitter pe, PE_EFFECT effect);
void PE_Emitter_SetFlash(ParticleEmitter pe, PE_EFFECT effect);
void PE_Emitter_SetSpin(ParticleEmitter pe, PE_EFFECT effect);
void PE_Emitter_SetShrink(ParticleEmitter pe, PE_EFFECT effect);
void PE_Emitter_SetGrow(ParticleEmitter pe, PE_EFFECT effect);

void PE_Emitter_Run(ParticleEmitter pe);

void PE_Particle_SetSize(ParticleEmitter pe, float size);
void PE_Particle_SetShape(ParticleEmitter pe, PE_SHAPE shape);
void PE_Particle_SetSpeed(ParticleEmitter pe, float speed);
void PE_Particle_SetAcceleration(ParticleEmitter pe, float acceleration);
void PE_Particle_SetWeight(ParticleEmitter pe, float weight);
void PE_Particle_SetLifespan(ParticleEmitter pe, int lifespan);

void PE_Particle_Add(ParticleEmitter pe);

#endif