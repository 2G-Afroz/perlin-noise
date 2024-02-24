#include "../include/perlin_noise.h"

float interpolate(float a, float b, float t)
{

	// if (0.0 > t)
	// 	return a;
	// if (1.0 < t)
	// 	return b;

	// This is linear interpolation. I does not provide smooth appearance.
	//return a + t * (b - a);

	// Use this cubic interpolation instead, for a smooth appearance:
	return a + t * t * (3.0 - 2.0 * t) * (b - a);

	// Use this for an even smoother result with a second derivative equal to zero on boundaries:
	//return a + t * t * t * (t * (6.0 * t - 15.0) + 10.0) * (b - a);
}

float getRandom(float x)
{
	// No precomputed gradients mean this works for any number of grid coordinates
	const unsigned w = 8 * sizeof(unsigned);
	const unsigned s = w / 2; // rotation width
	unsigned a = x;
	a *= 3284157443u;
	a ^= a << s | a >> (w - s);
	a *= 1911520717u;
	a ^= a << s | a >> (w - s);
	a *= 2048419325u;

	// Scale the random value to [-0.5, 0.5]
	float random = static_cast<float>(a) / static_cast<float>(~(0u)) -0.5f;

	return random;
}

float map(float value, float fromLow, float fromHigh, float toLow, float toHigh){
 	// Ensure the input value is within the current range
    value = std::min(std::max(value, fromLow), fromHigh);

    // Map the value to the target range
    return toLow + (toHigh - toLow) * ((value - fromLow) / (fromHigh - fromLow));
}

float perlinNoise(float x, int octaves) {
	float frequency = 1.0f;
	float amplitude = 1.0f;
	float total = 0;

	for (int i = 0; i < octaves; i++) {
		x *= frequency;
		float x0 = (float)floor(x);
		float x1 = x0 + 1;

		float gX0 = map(getRandom(x0), -0.5f, 0.5f, -amplitude/2, amplitude/2);
		float gX1 = map(getRandom(x1), -0.5f, 0.5f, -amplitude/2, amplitude/2);

		float t = x - x0;

		total += interpolate(gX0, gX1, t);

		frequency *= 2.0f;
		amplitude *= 0.5f;
	}

	return total;
}

//### FOR 2D PERLIN NOISE ###//
struct vector2 {
	float x, y;
};

vector2 getRandom(float x, float y) {
	// No precomputed gradients mean this works for any number of grid coordinates
    const unsigned w = 8 * sizeof(unsigned);
    const unsigned s = w / 2; // rotation width
    unsigned a = x, b = y;
    a *= 3284157443; b ^= a << s | a >> (w-s);
    b *= 1911520717; a ^= b << s | b >> (w-s);
    a *= 2048419325;
    float random = a * (3.14159265 / ~(~0u >> 1)); // in [0, 2*Pi]
    vector2 v;
    v.x = cos(random);	// Return value between -1 to 1.
	v.y = sin(random);	// Return value between -1 to 1.
    return v;
}

float dotGridPoint(int ix, int iy, float x, float y) {
	vector2 rand = getRandom(ix, iy);

	float dx = x - (float)ix;
	float dy = y - (float)iy;

	return (dx * rand.x + dy * rand.y);
}

float perlinNoise(float x, float y, int octaves) {

	int x0 = (int)floor(x);
	int x1 = x0 + 1;
	int y0 = (int)floor(y);
	int y1 = y0 + 1;

	float xt = x - (float)x0;
	float yt = y - (float)y0;

	float n0 = dotGridPoint(x0, y0, x, y);
	float n1 = dotGridPoint(x1, y0, x, y);
	float xn = interpolate(n0, n1, xt);

	n0 = dotGridPoint(x0, y1, x, y);
	n1 = dotGridPoint(x1, y1, x, y);
	float yn = interpolate(n0, n1, xt);

	return map(interpolate(xn, yn, yt), -0.7f, 0.7f, -1.0f, 1.0f);	// Return value between -1 and 1
}