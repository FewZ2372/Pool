#pragma once
#include "Camera.h"

void drawBalls(BALL ball)
{
    DrawCircle((int)ball.position.x, (int)ball.position.y, ball.radius, WHITE); // La bola blanca.

    DrawCircle(GetScreenWidth() / 2, 150, 10, RED);
}

void drawTable()
{
    DrawRectangle(150, 50, 600, 800, DARKGREEN);
    DrawRectangleLinesEx(Rectangle{ 150, 50, 600, 800 }, 15, DARKBROWN);
}