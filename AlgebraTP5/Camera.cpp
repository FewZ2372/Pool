#include "Camera.h"

#include "Balls.h"

#include "raylib.h"

void drawBalls(BALL ball)
{
	DrawCircle((int)ball.x, (int)ball.y, ball.radius, WHITE); // La bola blanca.

	DrawCircle(GetScreenWidth() / 2, 150, 10, RED);
}

void drawTable()
{
	DrawRectangle(150, 50, 600, 800, DARKGREEN);
	DrawRectangleLinesEx(Rectangle{ 150, 50, 600, 800 }, 15, DARKBROWN);
}

