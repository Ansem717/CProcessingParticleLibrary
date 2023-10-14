# CProcessing Particle Library
A custom library to create a Particle Emitter in CProcessing.  
Author: Andy Malik  
Created at Digipen  
© 2023 DigiPen (USA) Corporation  

## Download
The only necessary folder to download is the ParticleEmitter folder in this repo.  
[CONTROL + CLICK HERE TO DOWNLOAD ZIP](https://minhaskamal.github.io/DownGit/#/home?url=https:%2F%2Fgithub.com%2FAnsem717%2FCProcessingParticleLibrary%2Ftree%2Fmain%2FParticleEmitter).  
*Will open IN SAME TAB to DownGit. Special thanks to Minhas Kamal for this app.*  
Extract the ParticleEmitter folder into your repository.  

## Include
To use the library, you only need to include the emitter file.  
```c
#include "ParticleEmitter/ParticleEmitter.h"
```

# Usage
Refer to the functions below to learn how to use the Particle Emitter library.  
- [PE_New](https://github.com/Ansem717/CProcessingParticleLibrary#pe_new)
- PE_SetPosition
- PE_SetTargetMode
- PE_SetAngle
- PE_SetAngleRange
- PE_SetDelayMode
- PE_SetDelaySeconds
- PE_SetDelayFrames
<br />

- PE_AddEffect
- PE_RemoveEffect
- PE_ClearEffects
- PE_SetDelayFlashSeconds
- PE_SetDelayFlashFrames
- PE_SetGrowMode
- PE_SetGrowLimit
- PE_SetDelayGrowShrinkSeconds
- PE_SetDelayGrowShrinkFrames
<br />

- PE_SetSize
- PE_SetShape
- PE_SetColor
- PE_SetColorRandom
- PE_SetSpeed
- PE_SetAcceleration
- PE_SetWeight
- PE_SetLifespan
<br />

- PE_Add
- PE_AddMany
- PE_Run

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

void init(void) {
  pe = PE_New(CP_Vector_Create(400, 400));
}
```


<!-- void PE_SetPosition(ParticleEmitter* pe, CP_Vector position);
void PE_SetTargetMode(ParticleEmitter* pe, PE_TARGET_MODE mode);
void PE_SetAngle(ParticleEmitter* pe, float theta);
void PE_SetAngleRange(ParticleEmitter* pe, float thetaRange);
void PE_SetDelayMode(ParticleEmitter* pe, PE_DELAY_MODE mode);
void PE_SetDelaySeconds(ParticleEmitter* pe, float delaySeconds);
void PE_SetDelayFrames(ParticleEmitter* pe, int delayFrames);

void PE_AddEffect(ParticleEmitter* pe, PE_EFFECT effect, float value);
void PE_RemoveEffect(ParticleEmitter* pe, PE_EFFECT effect);
void PE_ClearEffects(ParticleEmitter* pe);
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








