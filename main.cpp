// main.cpp
#include <raylib.h>
#include <iostream>
#include "include/perlin_noise.h"
#define WINDOW_WIDTH 850
#define WINDOW_HEIGHT 850

int main() {
	// Initialize raylib
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "perlin-noise");

	float l = 0.00;

	// Main game loop
	while (!WindowShouldClose()) {
		// Draw
		BeginDrawing();
		ClearBackground(BLACK);

		float a = l;
		for(int i = 0; i < WINDOW_WIDTH; i++) {
			float b = 0.0f;
			for(int j = 0; j < WINDOW_HEIGHT; j++) {
				float noise = map(perlinNoise(a, b, 2), -1.0f, 1.0f, 0.0f, 1.0f);
				DrawPixel(i, j, ColorFromHSV(0,0,noise));
				b += 0.01;
			}
			a += 0.01;
		}

		EndDrawing();
	}
				
	// Clean up
	CloseWindow();
	return 0;
}
