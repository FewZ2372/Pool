#include "raylib.h"


#include <iostream>

#include "ball.h"
#include "Camera.h"


using namespace std;


int main()
{
	//              X       Y    radius  mass
	BALL ball = { 450.0f, 650.0f, 10.0f, 5.0f };

	BALL ball2 = createBall(450.0f, 650.0f, 10.0f, 5.0f);

	int windowWidth = 900; // Ancho de la ventana.
	int windowHeight = 900; // Alto de la ventana.
	string windowTitle = "pool"; // Título de la ventana.

	float initialForce = 5.0f; // La fuerza que se le va a dar con el taco.


	InitWindow(windowWidth, windowHeight, "pool");

	while (!WindowShouldClose())
	{	
		updateBall(ball2);

		if (IsKeyPressed(KEY_SPACE) && !ball2.inMovement)
		{
			ball2.inMovement = true;

			setSpeedBall(ball2, GetMousePosition(), initialForce);
		}

		cout << "Ball speed: (" << ball2.speed.x << ";" << ball2.speed.y << ")\n";

		BeginDrawing();
		ClearBackground(BLACK);

		drawTable();
		drawBalls(ball);
		drawBalls(ball2);

		EndDrawing();
	}
	return 0;

}






	
