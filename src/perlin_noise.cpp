#include "../include/perlin_noise.h"

float interpolate(float a, float b, float t) {

    if (0.0 > t) return a;
    if (1.0 < t) return b;

	// This is linear interpolation. I does not provide smooth appearance.
	return a + t * (b - a);

    // Use this cubic interpolation instead, for a smooth appearance:
	//return a + t * t * (3.0 - 2.0 * t) * (b - a);
   
    // Use this for an even smoother result with a second derivative equal to zero on boundaries:
    //return (b - a) * ((t * (t * 6.0 - 15.0) + 10.0) * t * t * t) + a;
	return a + t * t * t * (t * (6.0 * t - 15.0) + 10.0);
}

