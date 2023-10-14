//---------------------------------------------------------
// file:	main.c
// author:	Andy Malik
// email:	andy.malik@digipen.edu
//
// brief:	A demo of the library for particle effects
//
// documentation link:
// https://github.com/DigiPen-Faculty/CProcessing/wiki
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------

#include "cprocessing.h"
#include "ParticleEmitter.h"

ParticleEmitter pe;

void game_init(void)
{
	CP_System_SetWindowSize(800, 800);
	pe = PE_Emitter_New(CP_Vector_Set(400, 400));
	PE_Particle_SetColor(&pe, CP_Color_Create(200, 100, 0, 255));
	PE_Emitter_SetMode(&pe, PE_MODE_RADIAL);
	PE_Particle_SetLifespan(&pe, 10);
}

void game_update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));
	PE_Emitter_Run(&pe);
	for (int i = 0; i < 2; i++) {
		PE_Particle_Add(&pe);
	}
}

void game_exit(void)
{
}

int main(void)
{
	CP_Engine_SetNextGameState(game_init, game_update, game_exit);
	CP_Engine_Run();
	return 0;
}
