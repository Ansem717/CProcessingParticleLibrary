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

void game_init(void) {
	CP_System_SetWindowSize(800, 800);
	pe = PE_New(CP_Vector_Set(400, 400));
	PE_SetColor(&pe, CP_Color_Create(255, 255, 0, 255));
	PE_SetAngle(&pe, -60);
	PE_SetAngleRange(&pe, 20);
	PE_SetLifespan(&pe, 20);
	PE_SetDelayMode(&pe, PE_DELAY_MODE_FRAMES);
	PE_SetDelayFrames(&pe, 0);
	PE_SetWeight(&pe, 0);
	PE_SetSize(&pe, 5);

	//PE_Effect_AddEffect(&pe, PE_EFFECT_FADEOUT, 10);
}

void game_update(void) {
	PE_SetSpeed(&pe, CP_Random_RangeInt(1, 5));
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));
	PE_Run(&pe);

	if (CP_Input_KeyReleased(KEY_SPACE)) {
		PE_Add(&pe);
	}
}

void game_exit(void) {}

int main(void) {
	CP_Engine_SetNextGameState(game_init, game_update, game_exit);
	CP_Engine_Run();
	return 0;
}
