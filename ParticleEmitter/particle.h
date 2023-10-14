//---------------------------------------------------------
// file:	particle.h
// author:	Andy Malik
// email:	andy.malik@digipen.edu
//
// brief:	Header file for Particle
//
// Copyright � 2020 DigiPen, All rights reserved.
//---------------------------------------------------------

#ifndef PARTICLE_H
#define PARTICLE_H

typedef struct Particle {
	CP_Vector position, speed, acceleration; 
	float size, weight, rotation;
	int lifespan;
	PE_SHAPE shape;
	CP_Color color;
} Particle ;

Particle newParticle(CP_Vector position, float speed, float acceleration, float size, float theta, float weight, int lifespan, PE_SHAPE shape, CP_Color color);
void draw(Particle p);

#endif