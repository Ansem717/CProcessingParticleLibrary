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
#include "ParticleEmitter/ParticleEmitter.h"

ParticleEmitter peL;
ParticleEmitter peR;

void game_init(void) {
	CP_System_SetWindowSize(800, 800);
	peL = PE_New(CP_Vector_Set(380, 400));
	peR = PE_New(CP_Vector_Set(420, 400));
	PE_SetColor(&peR, CP_Color_Create(150, 150, 150, 100));
	PE_SetColor(&peL, CP_Color_Create(150, 150, 150, 100));
	PE_SetAngle(&peL, -65);
	PE_SetAngle(&peR, 65);
	PE_SetAngleRange(&peL, 15);
	PE_SetAngleRange(&peR, 15);
	PE_SetLifespan(&peR, 100);
	PE_SetLifespan(&peL, 100);
	PE_SetDelayMode(&peL, PE_DELAY_MODE_FRAMES);
	PE_SetDelayFrames(&peL, 0);
	PE_SetWeight(&peR, 0.02);
	PE_SetWeight(&peL, 0.02);
	PE_SetSize(&peR, 5);
	PE_SetSize(&peL, 12);
	PE_SetShape(&peL, PE_SHAPE_SQUARE);
	PE_SetSpeed(&peL, 4);
	PE_SetSpeed(&peR, 4);

	PE_AddEffect(&peL, PE_EFFECT_FADEOUT, 10);
	PE_AddEffect(&peR, PE_EFFECT_FADEOUT, 5);
}

void game_update(void) {
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));
	PE_Run(&peL);
	PE_Run(&peR);

	PE_SetColorRandom(&peL);
	PE_Add(&peL);

	if (CP_Input_KeyReleased(KEY_SPACE)) {
		PE_AddMany(&peL, 3);
		PE_AddMany(&peR, 3);
	}
}

void game_exit(void) {}

int main(void) {
	CP_Engine_SetNextGameState(game_init, game_update, game_exit);
	CP_Engine_Run();
	return 0;
}
