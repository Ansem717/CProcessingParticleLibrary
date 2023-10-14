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

ParticleEmitter pe;

void game_init(void) {
	CP_System_SetWindowSize(800, 800);
	pe = PE_New(CP_Vector_Set(380, 400));
	PE_SetColor(&pe, CP_Color_Create(100, 100, 0, 255));
	PE_SetAngle(&pe, -40);
	PE_SetAngleRange(&pe, 50);
	PE_SetLifespan(&pe, 100);
	PE_SetDelayMode(&pe, PE_DELAY_MODE_FRAMES);
	PE_SetDelayFrames(&pe, 5);
	PE_SetWeight(&pe, 0.05f);
	PE_SetSize(&pe, 9);
	PE_SetShape(&pe, PE_SHAPE_SQUARE);
	PE_SetSpeed(&pe, 6);

	PE_AddEffect(&pe, PE_EFFECT_FADEOUT, 5);
	PE_AddEffect(&pe, PE_EFFECT_SPIN, 20);
	PE_AddEffect(&pe, PE_EFFECT_FLASH, 70);
	PE_SetDelayFlashFrames(&pe, 2);
}

void game_update(void) {
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));
	PE_Run(&pe);

	//PE_SetColorRandom(&pe);

	//if (CP_Input_KeyReleased(KEY_SPACE)) {
		PE_AddMany(&pe, 4);
	//}
}

void game_exit(void) {}

int main(void) {
	CP_Engine_SetNextGameState(game_init, game_update, game_exit);
	CP_Engine_Run();
	return 0;
}
