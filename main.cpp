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
	float max = 0;
	float min = 0;

	// Main game loop
	while (!WindowShouldClose()) {
		// Draw
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Hello, 2G-Afroz!", 10, 10, 20, WHITE);

		float a = l;
		for(int i = 0; i < WINDOW_WIDTH; i++) {
			float b = 0.0f;
			for(int j = 0; j < WINDOW_HEIGHT; j++) {
				float noise = map(perlinNoise(a, b, 1), -1.0f, 1.0f, 0.0f, 1.0f);
				DrawPixel(i, j, ColorFromHSV(0,0,noise));
				if(noise > max)
					max = noise;
				if(noise < min)
					min = noise;			

				b += 0.1;
			}
			a += 0.1;
		}

		DrawText(TextFormat("MAX: %f\nMIN: %f", max, min), 10, 40, 20, RED);

		EndDrawing();
	}
				
	// Clean up
	CloseWindow();
	return 0;
}
