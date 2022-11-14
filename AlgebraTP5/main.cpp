#include "raylib.h"

int main()
{
	InitWindow(900, 900, "pool");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawCircle(GetScreenWidth()/2, GetScreenHeight()/2, 10, WHITE);

		DrawRectangleLines(150, 50, 600, 800, WHITE);

		DrawCircle(160, 60, 10, WHITE);
		DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 10, WHITE);
		

		EndDrawing();
	}
	return 0;
}