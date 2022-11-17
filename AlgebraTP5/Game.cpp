#include "Game.h"

void game()
{
	//              X       Y    radius  mass
	BALL ball1 = createBall(450.0f, 650.0f, 10.0f, 5.0f, WHITE);
	BALL ball2 = createBall(450.0f, 650.0f, 10.0f, 5.0f, RED);
	PLAYER P1 = CreatePlayer();

	while (!WindowShouldClose())
	{
		//ball
		if (IsKeyPressed(KEY_SPACE) && !ball1.inMovement)
		{
			ball1.inMovement = true;

			setSpeedBall(ball1, GetMousePosition(), 15);
		}
		updateBall(ball1);

		PlayerMove(P1, ball1);

		//draw
		BeginDrawing();
		ClearBackground(BLACK);

		drawTable();
		drawBalls(ball1);

		DrawRectanglePro(P1.rec, P1.origin, P1.rotation, BROWN);
		DrawCircleLines(static_cast<int>(ball1.position.x), static_cast<int>(ball1.position.y), ball1.radius * 3, RED);

		EndDrawing();

	}
}