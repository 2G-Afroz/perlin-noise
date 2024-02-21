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

float getRandom(float x) {
     // No precomputed gradients mean this works for any number of grid coordinates
    const unsigned w = 8 * sizeof(unsigned);
    const unsigned s = w / 2; // rotation width
    unsigned a = x;
    a *= 3284157443u; 
    a ^= a << s | a >> (w-s);
    a *= 1911520717u;
    a ^= a << s | a >> (w-s);
    a *= 2048419325u;

    // Scale the random value to [0, 1]
    float random = static_cast<float>(a) / static_cast<float>(~(0u));

    return random;
}
