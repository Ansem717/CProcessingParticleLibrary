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
	PE_Particle_SetColor(&pe, CP_Color_Create(0, 200, 0, 255));
	PE_Emitter_SetAngle(&pe, 50);
	PE_Emitter_SetAngleRange(&pe, 20);
	PE_Particle_SetLifespan(&pe, 1000);
	PE_Particle_SetSpeed(&pe, 10);
	PE_Emitter_SetDelayMode(&pe, PE_DELAY_MODE_SECONDS);
	PE_Emitter_SetDelaySeconds(&pe, 0);// .25);
}

void game_update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));
	PE_Emitter_Run(&pe);
	PE_Particle_Add(&pe);

	PE_Particle_SetColorRandom(&pe);

	if (CP_Input_KeyReleased(KEY_SPACE)) {
		PE_Particle_SetShape(&pe, PE_SHAPE_SQUARE);
	} else if (CP_Input_KeyReleased(KEY_K)) {
		PE_Particle_SetShape(&pe, PE_SHAPE_CIRCLE);
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
