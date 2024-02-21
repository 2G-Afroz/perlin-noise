// main.cpp
#include <raylib.h>
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
		DrawText("Hello, 2G-Afroz!", 10, 10, 20, WHITE);
		float a = l;
		for(int i = 0; i < WINDOW_WIDTH; i++) {
			float noise = perlinNoise(a, 3) * 100 + 400;
			DrawCircle(i, noise, 1, WHITE);
			a += 0.003;
		}
		l += 0.001;
		EndDrawing();
	}
				
	// Clean up
	CloseWindow();
	return 0;
}
