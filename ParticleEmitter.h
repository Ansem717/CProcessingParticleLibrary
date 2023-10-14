//---------------------------------------------------------
// file:	ParticleEmitter.h
// author:	Andy Malik
// email:	andy.malik@digipen.edu
//
// brief:	Header for Particle system
//
// Copyright © 2023 DigiPen, All rights reserved.
//---------------------------------------------------------

#ifndef PARTICLE_EMITTER_H
#define PARTICLE_EMITTER_H

#define PE_PARTICLE_ARR_SIZE 50
#define PE_EFFECT_ARR_SIZE 5

typedef enum PE_TARGET_MODE {
	PE_TARGET_MODE_DIRECTIONAL,
	PE_TARGET_MODE_RADIAL
} PE_TARGET_MODE;

typedef enum PE_DELAY_MODE {
	PE_DELAY_MODE_SECONDS,
	PE_DELAY_MODE_FRAMES
} PE_DELAY_MODE;

typedef enum PE_EFFECT {
	PE_EFFECT_FADEOUT,	//0 ;; Used as array index in pe->effects[]. Value returns 0 (false) or 1 (true).
	PE_EFFECT_FLASH,	//1 ;; Used as array index in pe->effects[]. Value returns 0 (false) or 1 (true).
	PE_EFFECT_SPIN,		//2 ;; Used as array index in pe->effects[]. Value returns 0 (false) or 1 (true).
	PE_EFFECT_SHRINK,	//3 ;; Used as array index in pe->effects[]. Value returns 0 (false) or 1 (true).
	PE_EFFECT_GROW		//4 ;; Used as array index in pe->effects[]. Value returns 0 (false) or 1 (true).
} PE_EFFECT ;

typedef enum PE_SHAPE {
	PE_SHAPE_CIRCLE,
	PE_SHAPE_SQUARE
} PE_SHAPE;

#include "cprocessing.h"
#include "particle.h"

typedef struct ParticleEmitter {
	CP_Vector position;
	PE_TARGET_MODE targetMode; //PE_MODE_DIRECTIONAL emits the particles in a specific direction; PE_MODE_RADIAL emits the particles in a random circle.
	float directionalAngle; //0 degrees is north
	float directionalRange; //0 means all particles have no randomness when spawned.
	int count; //current number of particles; LIMIT IS 50 (PE_PARTICLE_ARR_SIZE)
	int effects[PE_EFFECT_ARR_SIZE]; //Boolean array of effects. LIMIT IS 5 (PE_EFFECT_ARR_SIZE)

	float size; //Initial size of particle
	PE_SHAPE shape; //Shape of each particle.
	CP_Color col; //Color of each particle.
	float speed; //Initial speed of particle.
	float acceleration; //Gain (or negative for Loss) of speed over time.
	float weight; //Higher weight, the more relevant gravity; Weight = 0 means no fall. 
	int lifespan; //Number of frames the particle will exist

	Particle particles[50]; //particles array
	int head; //head of the array
	int tail; //tail of the array

	float delaySeconds; //delay in seconds to slow down particle generation
	int delayFrames; //delay in frames to slow down particle generation
	PE_DELAY_MODE delayMode; //Mode to abide which delay
	float _delayTimestamp; //most recent timestamp for the delay check
} ParticleEmitter;

ParticleEmitter PE_Emitter_New(CP_Vector position);

void PE_Emitter_SetPosition(ParticleEmitter* pe, CP_Vector position);
void PE_Emitter_SetTargetMode(ParticleEmitter* pe, PE_TARGET_MODE mode);
void PE_Emitter_SetAngle(ParticleEmitter* pe, float theta);
void PE_Emitter_SetAngleRange(ParticleEmitter* pe, float thetaRange);
void PE_Emitter_SetDelaySeconds(ParticleEmitter* pe, float delaySeconds);
void PE_Emitter_SetDelayFrames(ParticleEmitter* pe, int delayFrames);
void PE_Emitter_SetDelayMode(ParticleEmitter* pe, PE_DELAY_MODE);

void PE_Effect_AddEffect(ParticleEmitter* pe, PE_EFFECT effect);
void PE_Effect_RemoveEffect(ParticleEmitter* pe, PE_EFFECT effect);
void PE_Effect_ClearEffects(ParticleEmitter* pe);

void PE_Particle_SetSize(ParticleEmitter* pe, float size);
void PE_Particle_SetShape(ParticleEmitter* pe, PE_SHAPE shape);
void PE_Particle_SetColorRandom(ParticleEmitter* pe);
void PE_Particle_SetColor(ParticleEmitter* pe, CP_Color color);
void PE_Particle_SetSpeed(ParticleEmitter* pe, float speed);
void PE_Particle_SetAcceleration(ParticleEmitter* pe, float acceleration);
void PE_Particle_SetWeight(ParticleEmitter* pe, float weight);
void PE_Particle_SetLifespan(ParticleEmitter* pe, int lifespan);

void PE_Particle_Add(ParticleEmitter* pe);
void PE_Emitter_Run(ParticleEmitter* pe);

#endif