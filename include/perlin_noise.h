#ifndef PERLIN_NOISE_H
#define PERLIN_NOISE_H
#include <cmath>
#include <algorithm>

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

/**
 * @brief Generates a pseudo-random float value based on the input.
 *
 * This function generates pseudo-random float values between -0.5 and 0.5
 * using bitwise operations on the input value.
 *
 * @param x The input value used to generate the random number.
 * @return A pseudo-random float value between -0.5 and 0.5.
 */
float getRandom(float x);

/**
 * @brief Maps a value from one range to another.
 *
 * This function takes a value and maps it from a source range to a target range.
 *
 * @param value The input value to be mapped.
 * @param fromLow The lower bound of the source range.
 * @param fromHigh The upper bound of the source range.
 * @param toLow The lower bound of the target range.
 * @param toHigh The upper bound of the target range.
 * @return The mapped value in the target range.
 */
float map(float value, float fromLow, float fromHigh, float toLow, float toHigh);

/**
 * @brief Generates Perlin noise based on the input value.
 *
 * This function generates Perlin noise by combining multiple octaves of
 * random noise using a series of interpolations.
 *
 * @param x The input value used to generate Perlin noise.
 * @param octaves The number of octaves used to generate the noise. Defaults to 2 if not specified.
 * @return The Perlin noise value at the given input position.
 */
float perlinNoise(float x, int octaves = 2);


//###### FOR 2D PERLIN NOISE #######//
/**
 * @brief this is 2D vector which have x-axis and y-axis.
 * 
 */
struct vector2;

/**
 * @brief Generates a pseudo-random float value based on the input.
 *
 * This function generates pseudo-random vector2 values between -1 and 1
 * using bitwise operations on the input value.
 *
 * @param x The input value used to generate the random number.
 * @param y	The y-axis input value used to generate the random number.
 * @return vector2 pseudo-random float value between -1 and 1.
 */
vector2 getRandom(float x, float y);

/**
 * Computes the dot product between the gradient vectors at the grid points
 * and the distance vectors from the grid points to the given point (x, y).
 * This function is part of the Perlin noise generation process.
 *
 * @param ix The x-coordinate of the grid point.
 * @param iy The y-coordinate of the grid point.
 * @param x The x-coordinate of the point for which the dot product is computed.
 * @param y The y-coordinate of the point for which the dot product is computed.
 * @return The dot product between the gradient vectors and the distance vectors,
 *         providing a smoothed noise value.
 */
float dotGridPoint(float ix, float iy, float x, float y);

/**
 * Generates Perlin noise at the given coordinates (x, y) using multiple octaves.
 *
 * @param x The x-coordinate for which Perlin noise is generated.
 * @param y The y-coordinate for which Perlin noise is generated.
 * @param octaves The number of octaves used for generating Perlin noise.
 * @return The Perlin noise value at the specified coordinates.
 */
float perlinNoise(float x, float y, int octaves = 2);

#endif