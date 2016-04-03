#ifndef LAUNCH_H
#define LAUNCH_H
#ifdef __cplusplus
extern "C" {
#endif
#include "cube.h"

// Total number of effects
// Used in the main loop to loop through all the effects one by bone.
// Set this number one higher than the highest number inside switch()
// in launch_effect() in launch_effect.c
#define EFFECTS_TOTAL 28

void launch_effect(int effect);
#ifdef __cplusplus
}
#endif
#endif

