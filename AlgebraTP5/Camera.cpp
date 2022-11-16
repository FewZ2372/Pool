#include "Camera.h"

#include "ball.h"

#include "raylib.h"

void drawBalls(BALL ball)
{
	DrawCircle(GetScreenWidth() / 2, 150, 10, RED);

	drawBall(ball);
}

void drawTable()
{
	DrawRectangle(150, 50, 600, 800, DARKGREEN);
	DrawRectangleLinesEx(Rectangle{ 150, 50, 600, 800 }, 15, DARKBROWN);
}

