# CProcessing Particle Library
A custom library to create a Particle Emitter in CProcessing.  
Author: Andy Malik  
Created at Digipen  
© 2023 DigiPen (USA) Corporation  

## Download
The only necessary folder to download is the ParticleEmitter folder in this repo.  
[CTRL+CLICK HERE TO DOWNLOAD ZIP](https://minhaskamal.github.io/DownGit/#/home?url=https:%2F%2Fgithub.com%2FAnsem717%2FCProcessingParticleLibrary%2Ftree%2Fmain%2FParticleEmitter).  
*Will open DownGit. Special thanks to Minhas Kamal for this app.*  
Extract the ParticleEmitter folder into your repository.  

## Include
To use the library, you only need to include the emitter file.  
```c
#include "ParticleEmitter/ParticleEmitter.h"
```

# Usage
Refer to the functions below to learn how to use the Particle Emitter library.  
- [PE_New](https://github.com/Ansem717/CProcessingParticleLibrary#pe_new)
- [PE_SetPosition](https://github.com/Ansem717/CProcessingParticleLibrary#pe_setposition)
- [PE_SetTargetMode](https://github.com/Ansem717/CProcessingParticleLibrary#pe_settargetmode)
- [PE_SetAngle](https://github.com/Ansem717/CProcessingParticleLibrary#pe_setangle)
- [PE_SetAngleRange](https://github.com/Ansem717/CProcessingParticleLibrary#pe_setanglerange)
- [PE_SetDelayMode](https://github.com/Ansem717/CProcessingParticleLibrary#pe_setdelaymode)
- [PE_SetDelaySeconds](https://github.com/Ansem717/CProcessingParticleLibrary#pe_setdelayseconds)
- [PE_SetDelayFrames](https://github.com/Ansem717/CProcessingParticleLibrary#pe_setdelayframes)
<br />

- [PE_AddEffect](https://github.com/Ansem717/CProcessingParticleLibrary#pe_addeffect)
- [PE_RemoveEffect](https://github.com/Ansem717/CProcessingParticleLibrary#pe_removeeffect)
- [PE_ClearEffects](https://github.com/Ansem717/CProcessingParticleLibrary#pe_cleareffects)
- [PE_SetDelayFlashSeconds](https://github.com/Ansem717/CProcessingParticleLibrary#pe_setdelayflashseconds)
- [PE_SetDelayFlashFrames](https://github.com/Ansem717/CProcessingParticleLibrary#pe_setdelayflashframes)
- [PE_SetGrowMode](https://github.com/Ansem717/CProcessingParticleLibrary#pe_setgrowmode)
- [PE_SetGrowLimit](https://github.com/Ansem717/CProcessingParticleLibrary#pe_setgrowlimit)
- [PE_SetDelayGrowShrinkSeconds](https://github.com/Ansem717/CProcessingParticleLibrary#pe_setdelaygrowshrinkseconds)
- [PE_SetDelayGrowShrinkFrames](https://github.com/Ansem717/CProcessingParticleLibrary#pe_setdelaygrowshrinkframes)
<br />

- [PE_SetSize](https://github.com/Ansem717/CProcessingParticleLibrary#pe_setsize)
- [PE_SetShape](https://github.com/Ansem717/CProcessingParticleLibrary#pe_setshape)
- [PE_SetColor](https://github.com/Ansem717/CProcessingParticleLibrary#pe_setcolor)
- [PE_SetColorRandom](https://github.com/Ansem717/CProcessingParticleLibrary#pe_setcolorrandom)
- [PE_SetSpeed](https://github.com/Ansem717/CProcessingParticleLibrary#pe_setspeed)
- [PE_SetAcceleration](https://github.com/Ansem717/CProcessingParticleLibrary#pe_setacceleration)
- [PE_SetWeight](https://github.com/Ansem717/CProcessingParticleLibrary#pe_setweight)
- [PE_SetLifespan](https://github.com/Ansem717/CProcessingParticleLibrary#pe_setlifespan)
<br />

- [PE_Add](https://github.com/Ansem717/CProcessingParticleLibrary#pe_add)
- [PE_AddMany](https://github.com/Ansem717/CProcessingParticleLibrary#pe_addmany)
- [PE_Run](https://github.com/Ansem717/CProcessingParticleLibrary#pe_run)

# PE_New
Create a new Particle Emitter at a CP_Vector position. 
## Function
```c
ParticleEmitter PE_New(CP_Vector position);
```
### Parameters
- position (CP_Vector) - the origin position of the emitter on the screen.
### Return
- ParticleEmitter - An emitter at the given position.
## Example
```c
ParticleEmitter pe;

void init() {
  pe = PE_New(CP_Vector_Set(400, 400));
}
```
[Back to Top](https://github.com/Ansem717/CProcessingParticleLibrary#usage)
# PE_SetPosition
Sets the position of a given Particle Emitter (pointer) to a given CP_Vector.
## Function
```c
void PE_SetPosition(ParticleEmitter* pe, CP_Vector position);
```
### Parameters
- pe (ParticleEmitter*) - a pointer to the particle emitter
- position (CP_Vector) - the new position to set the emitter to.
### Return
This function does not return anything.
## Example
```c
ParticleEmitter pe;

void init() {
  pe = PE_New(CP_Vector_Set(400, 400));
  PE_SetPosition(&pe, CP_Vector_Set(200, 200));
}
```
[Back to Top](https://github.com/Ansem717/CProcessingParticleLibrary#usage)
# PE_SetTargetMode
Sets the Target Mode of a given Particle Emitter (pointer) to the desired mode. Two modes are:
- `PE_TARGET_MODE_DIRECTIONAL` :: Default mode. The particles will aim in a conical direction based on the direction angle and direction range.
- `PE_TARGET_MODE_RADIAL` :: The particles will aim in any random direction, ignoring angle and range.
## Function
```c
void PE_SetTargetMode(ParticleEmitter* pe, PE_TARGET_MODE mode);
```
### Parameters
- pe (ParticleEmitter*) - a pointer to the particle emitter
- mode (PE_TARGET_MODE) - the mode to swap to.
### Return
This function does not return anything.
## Example
```c
ParticleEmitter pe;

void init() {
  pe = PE_New(CP_Vector_Set(400, 400));
  PE_SetTargetMode(&pe, PE_TARGET_MODE_RADIAL);
}
```
[Back to Top](https://github.com/Ansem717/CProcessingParticleLibrary#usage)
# PE_SetAngle
Sets the initial direction angle (degrees) for particles when using PE_TARGET_MODE_DIRECTIONAL.
- If the angle is 0, the particles aim vertical.
- If the angle is 90, the particles aim to the right.
- If the angle is 180, the particles aim down.
- If the angle is 270 (or -90), the particles aim to the left.
## Function
```c
void PE_SetAngle(ParticleEmitter* pe, float theta);
```
### Parameters
- pe (ParticleEmitter*) - a pointer to the particle emitter
- theta (float) - the angle to set
### Return
This function does not return anything.
## Example
```c
ParticleEmitter pe;

void init() {
  pe = PE_New(CP_Vector_Set(400, 400));
  PE_SetTargetMode(&pe, PE_TARGET_MODE_DIRECTIONAL);
  PE_SetAngle(&pe, 45); //all particles will emit towards the top right
}
```
[Back to Top](https://github.com/Ansem717/CProcessingParticleLibrary#usage)
# PE_SetAngleRange
Sets the range for randomness originating from the directional angle. 
## Function
```c
void PE_SetAngleRange(ParticleEmitter* pe, float thetaRange);
```
### Parameters
- pe (ParticleEmitter*) - a pointer to the particle emitter
- thetaRange (float) - the range for randomness
### Return
This function does not return anything.
## Example
```c
ParticleEmitter pe;

void init() {
  pe = PE_New(CP_Vector_Set(400, 400));
  PE_SetTargetMode(&pe, PE_TARGET_MODE_DIRECTIONAL);
  PE_SetAngle(&pe, 45); //all particles will emit towards the top right
  PE_SetAngleRange(&pe, 15); //now all particles will emit between angles 30 and 60, chosen randomly
}
```
[Back to Top](https://github.com/Ansem717/CProcessingParticleLibrary#usage)
# PE_SetDelayMode
Sets the Delay Mode for calculating emission and effect delays. There are two options:
- `PE_DELAY_MODE_SECONDS` :: Default mode. Uses the delay seconds set from SetDelaySeconds to calculate delay.
- `PE_DELAY_MODE_FRAMES` :: Uses the delay frames set from SetDelayFrames to calculate delay.
## Function
```c
void PE_SetDelayMode(ParticleEmitter* pe, PE_DELAY_MODE mode);
```
### Parameters
- pe (ParticleEmitter*) - a pointer to the particle emitter
- mode (PE_DELAY_MODE) - the mode for calculating delay
### Return
This function does not return anything.
## Example
```c
ParticleEmitter pe;

void init() {
  pe = PE_New(CP_Vector_Set(400, 400));
  PE_SetDelayMode(&pe, PE_DELAY_MODE_FRAMES);
  PE_SetDelayFrames(&pe, 5); //prevent new particles within 5 frames of the most recent one.
}
```
[Back to Top](https://github.com/Ansem717/CProcessingParticleLibrary#usage)
# PE_SetDelaySeconds
Sets the number of seconds to wait between particle emissions and effects. Only usable if PE_DELAY_MODE_SECONDS is set.
## Function
```c
void PE_SetDelaySeconds(ParticleEmitter* pe, float delaySeconds);
```
### Parameters
- pe (ParticleEmitter*) - a pointer to the particle emitter
- delaySeconds (float) - the number of seconds to wait before allowing new particles
### Return
This function does not return anything.
## Example
```c
ParticleEmitter pe;

void init() {
  pe = PE_New(CP_Vector_Set(400, 400));
  PE_SetDelayMode(&pe, PE_DELAY_MODE_SECONDS);
  PE_SetDelaySeconds(&pe, 2); //prevent new particles within 2 seconds of the most recent one.
}
```
[Back to Top](https://github.com/Ansem717/CProcessingParticleLibrary#usage)
# PE_SetDelayFrames
Sets the number of frames to wait between particle emissions and effects. Only usable if PE_DELAY_MODE_FRAMES is set.
## Function
```c
void PE_SetDelayFrames(ParticleEmitter* pe, int delayFrames);
```
### Parameters
- pe (ParticleEmitter*) - a pointer to the particle emitter
- int (delayFrames) - the number of frames to wait before allowing new particles
### Return
This function does not return anything.
## Example
```c
ParticleEmitter pe;

void init() {
  pe = PE_New(CP_Vector_Set(400, 400));
  PE_SetDelayMode(&pe, PE_DELAY_MODE_FRAMES);
  PE_SetDelayFrames(&pe, 5); //prevent new particles within 5 frames of the most recent one.
}
```
[Back to Top](https://github.com/Ansem717/CProcessingParticleLibrary#usage)
# PE_AddEffect
Adds an effect to the particle emitter set to the given value. Effects include:
- `PE_EFFECT_FADEOUT` :: Particles fadeout during lifetime at a rate provided by the given float. Values best between 2 and 10. Particles fully faded out are dequeued.
- `PE_EFFECT_FLASH` :: Particles flash back and forth between original color and the same color with lightness increased by given float. Values best at around 60 value with a dark base color. Use PE_setDelayFlash to determine how fast it flashes.
- `PE_EFFECT_SPIN` :: Particles rotate clockwise during lifetime. Only noticable with PE_SHAPE_SQUARE. Values best between 5 and 30.
- `PE_EFFECT_SHRINK` :: Particles shrink during lifetime at a rate provided by the given float. Values best between 0.1f and 1.0f. Particles fully shrunk are dequeued.
- `PE_EFFECT_GROW` :: Particles grow during lifetime at a rate provided by the given float. Values best between 0.1f and 1.0f.
  - If growLimit is set, then particles will either stop or dequeue when hitting the growlimit, based on the chosen PE_GROW_MODE.
  - If PE_EFFECT_GROW and PE_EFFECT_SHRINK are both active, the Particle will waver between `size - SHRINK VALUE` and `size + GROW VALUE`. Use PE_setDelayGrowShrink to determine how fast it wavers. When using Shrink and Grow together, given values are best as integers relative to the original size. 
## Function
```c
void PE_AddEffect(ParticleEmitter* pe, PE_EFFECT effect, float value);
```
### Parameters
- pe (ParticleEmitter*) - a pointer to the particle emitter
- effect (PE_EFFECT) - the effect to set
- value (float) - the value to set it to.
### Return
This function does not return anything.
## Examples
```c
ParticleEmitter pe;

void init() {
  pe = PE_New(CP_Vector_Set(400, 400));
  PE_SetDelayMode(&pe, PE_DELAY_MODE_FRAMES);

  PE_AddEffect(&pe, PE_EFFECT_FADEOUT, 4);

  PE_SetColor(&pe, CP_Color_Create(100, 0, 0, 255)); //set a dark red color
  PE_SetFlashDelayFrames(&pe, 3); //wait 3 frames before switching to the next color
  PE_AddEffect(&pe, PE_EFFECT_FLASH, 70); //bright flash

  PE_AddEffect(&pe, PE_EFFECT_GROW, 0.3f);
  PE_SetGrowMode(&pe, PE_GROW_MODE_STOP); //when growing hits the grow limit, just stop growing.
  PE_SetGrowLimit(&pe, 20); //Stop growing when size equals 20.
}
```
```c
ParticleEmitter pe;

void init() {
  pe = PE_New(CP_Vector_Set(400,400));
  PE_SetDelayMode(&pe, PE_DELAY_MODE_SECONDS); //use SECONDS

  PE_AddEffect(&pe, PE_EFFECT_SHRINK, 5);
  PE_AddEffect(&pe, PE_EFFECT_GROW, 5);
  //Both grow and shrink means we will swap between SIZE - 5 (shrink) and SIZE + 5 (grow).
  PE_SetDelayGrowShrinkSeconds(&pe, 1); //wait 1 second when swapping between the two sizes.
}
```
[Back to Top](https://github.com/Ansem717/CProcessingParticleLibrary#usage)
# PE_RemoveEffect
Removes the given effect from the Particle Emitter
## Function
```c
void PE_RemoveEffect(ParticleEmitter* pe, PE_EFFECT effect);
```
### Parameters
- pe (ParticleEmitter*) - a pointer to the particle emitter
- effect (PE_EFFECT) - the effect to remove
### Return
This function does not return anything.
## Example
```c
void update() {
  if (CP_Input_KeyReleased(KEY_SPACE)) {
    PE_RemoveEffect(&pe, PE_EFFECT_GROW);
  }
}
```
[Back to Top](https://github.com/Ansem717/CProcessingParticleLibrary#usage)
# PE_ClearEffects
Clears all the effects on the particle emitter
## Function
```c
void PE_ClearEffects(ParticleEmitter* pe);
```
### Parameters
- pe (ParticleEmitter*) - a pointer to the particle emitter
### Return
This function does not return anything.
## Example
```c
void update() {
  if (CP_Input_KeyReleased(KEY_SPACE)) {
    PE_ClearEffects(&pe);
  }
}
```
[Back to Top](https://github.com/Ansem717/CProcessingParticleLibrary#usage)
<!--# PE_SetDelayFrames
Sets the number of frames to wait between particle emissions and effects. Only usable if PE_DELAY_MODE_FRAMES is set.
## Function
```c
void PE_SetDelayFlashSeconds(ParticleEmitter* pe, float delayFlashSeconds);
void PE_SetDelayFlashFrames(ParticleEmitter* pe, int delayFlashFrames);
void PE_SetGrowMode(ParticleEmitter* pe, PE_GROW_MODE mode);
void PE_SetGrowLimit(ParticleEmitter* pe, float growLimit);
void PE_SetDelayGrowShrinkSeconds(ParticleEmitter* pe, float delayGrowShrinkSeconds);
void PE_SetDelayGrowShrinkFrames(ParticleEmitter* pe, int delayGrowShrinkFrames);

void PE_SetSize(ParticleEmitter* pe, float size);
void PE_SetShape(ParticleEmitter* pe, PE_SHAPE shape);
void PE_SetColor(ParticleEmitter* pe, CP_Color color);
void PE_SetColorRandom(ParticleEmitter* pe);
void PE_SetSpeed(ParticleEmitter* pe, float speed);
void PE_SetAcceleration(ParticleEmitter* pe, float acceleration);
void PE_SetWeight(ParticleEmitter* pe, float weight);
void PE_SetLifespan(ParticleEmitter* pe, int lifespan);

void PE_Add(ParticleEmitter* pe);
void PE_AddMany(ParticleEmitter* pe, int amount);
void PE_Run(ParticleEmitter* pe); -->








