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
// Copyright © 2023 DigiPen, All rights reserved.
//---------------------------------------------------------

#include "cprocessing.h"
#include "ParticleEmitter/ParticleEmitter.h"

ParticleEmitter pe;

void game_init(void) {
	CP_System_SetWindowSize(800, 800);
	pe = PE_New(CP_Vector_Set(380, 400));
	PE_SetColor(&pe, CP_Color_Create(0, 200, 0, 255));
	PE_SetAngle(&pe, 0);
	PE_SetAngleRange(&pe, 50);
	PE_SetLifespan(&pe, 70);
	PE_SetDelayMode(&pe, PE_DELAY_MODE_FRAMES);
	PE_SetDelayFrames(&pe, 2);
	PE_SetWeight(&pe, 0.01f);
	PE_SetSize(&pe, 15);
	PE_SetShape(&pe, PE_SHAPE_CIRCLE);
	PE_SetSpeed(&pe, 6);

	PE_SetDelayFlashFrames(&pe, 3);
	PE_SetGrowMode(&pe, PE_GROW_MODE_STOP);
	PE_SetGrowLimit(&pe, 30);
	PE_SetDelayGrowShrinkFrames(&pe, 2);
}

void game_update(void) {
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));
	PE_Run(&pe);

	PE_SetColorRandom(&pe);

	PE_Add(&pe);

	if (CP_Input_KeyReleased(KEY_R)) {
		if (pe.effects[PE_EFFECT_SPIN] == 0) {
			PE_AddEffect(&pe, PE_EFFECT_SPIN, 20);
		} else {
			PE_RemoveEffect(&pe, PE_EFFECT_SPIN);
		}
	}


	if (CP_Input_KeyReleased(KEY_S)) {
		if (pe.effects[PE_EFFECT_SHRINK] == 0) {
			PE_AddEffect(&pe, PE_EFFECT_SHRINK, 1);
		} else {
			PE_RemoveEffect(&pe, PE_EFFECT_SHRINK);
		}
	}

	if (CP_Input_KeyReleased(KEY_G)) {
		if (pe.effects[PE_EFFECT_GROW] == 0) {
			PE_AddEffect(&pe, PE_EFFECT_GROW, 1);
		} else {
			PE_RemoveEffect(&pe, PE_EFFECT_GROW);
		}
	}


	if (CP_Input_KeyReleased(KEY_F)) {
		if (pe.effects[PE_EFFECT_FLASH] == 0) {
			PE_AddEffect(&pe, PE_EFFECT_FLASH, 70);
		} else {
			PE_RemoveEffect(&pe, PE_EFFECT_FLASH);
		}
	}


	if (CP_Input_KeyReleased(KEY_D)) {
		if (pe.effects[PE_EFFECT_FADEOUT] == 0) {
			PE_AddEffect(&pe, PE_EFFECT_FADEOUT, 5);
		} else {
			PE_RemoveEffect(&pe, PE_EFFECT_FADEOUT);
		}
	}

	if (CP_Input_KeyReleased(KEY_C)) PE_ClearEffects(&pe);
}

void game_exit(void) {}

int main(void) {
	CP_Engine_SetNextGameState(game_init, game_update, game_exit);
	CP_Engine_Run();
	return 0;
}
