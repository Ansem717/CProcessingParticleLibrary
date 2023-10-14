//---------------------------------------------------------
// file:	particle.c
// author:	Andy Malik
// email:	andy.malik@digipen.edu
//
// brief:	Particle Model (simply holds data)
//
// Copyright © 2023 DigiPen, All rights reserved.
//---------------------------------------------------------

#include "cprocessing.h"
#include "ParticleEmitter.h"
#include "particle.h"
#include <math.h>

Particle newParticle(CP_Vector position, float speed, float acceleration, float size, float theta, float weight, int lifespan, PE_SHAPE shape, CP_Color color) {
	Particle p = {
		.position = position,
		.size = size,
		._size = size,
		.weight = weight,
		.lifespan = lifespan,
		.shape = shape,
		.color = color,
		._color = color,
		.flashToggle = 1,
		.sizeToggle = 1
	};
	theta = CP_Math_Radians(theta);
	p.speed = CP_Vector_Scale(CP_Vector_Set((float)sin(theta), (float)-cos(theta)), speed);
	p.acceleration = CP_Vector_Scale(CP_Vector_Set((float)sin(theta), (float)-cos(theta)), acceleration);
	return p;
}

void draw(Particle p) {
	CP_Settings_Save(); //Save current CPSettings before changing
	CP_Settings_Fill(p.color);
	CP_Settings_NoStroke();
	if (p.shape == PE_SHAPE_CIRCLE) {
		CP_Graphics_DrawCircle(p.position.x, p.position.y, p.size);
	} else {
		//PE_SHAPE_SQUARE
		CP_Settings_RectMode(CP_POSITION_CENTER);
		CP_Graphics_DrawRectAdvanced(p.position.x, p.position.y, p.size, p.size, p.rotation, 0);
	}
	CP_Settings_Restore(); //Restore previous CPSettings 
}
