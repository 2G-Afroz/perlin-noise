#ifndef PERLIN_NOISE_H
#define PERLIN_NOISE_H

/**
 * @brief Performs interpolation between two values.
 * 
 * Interpolation computes a value between two endpoints (a and b)
 * based on a parameter t that ranges from 0.0 to 1.0.
 * 
 * @param a The starting value.
 * @param b The ending value.
 * @param t The interpolation parameter, ranging from 0.0 to 1.0.
 * 
 * @return The interpolated value between a and b based on the parameter t.
 * 
 * @note For t = 0.0, the result is equal to 'a'. For t = 1.0, the result is equal to 'b'.
 *       For values of t between 0.0 and 1.0, the result is a interpolation between 'a' and 'b'.
 */
float interpolate(float a, float b, float t);

float getRandom(float x);

float perlinNoise(float x, int octaves = 2);


#endif