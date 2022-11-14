#include <iostream>

#include "raylib.h"

#include "Balls.h"

using std::cout;
using std::endl;
using std::string;



int main()
{
	//              X       Y    radius  mass
	BALL ball = { 450.0f, 400.0f, 10.0f, 5.0f };

	int windowWidth = 900; // Ancho de la ventana.
	int windowHeight = 900; // Alto de la ventana.
	string windowTitle = "pool"; // Título de la ventana.

	float ballSpeedY = 0.0f; // La velocidad de movimiento de la bola. Se actualiza en tiempo de ejecución.

	float initialForce = 15.0f; // La fuerza que se le va a dar con el taco.
	float torque = initialForce * ball.radius; // La fuerza que recibe la bola (fuerza angular). La fórmula de la
											   // fuerza angular es la fuerza inicial por el radio.

	// El rozamiento estático es igual a la masa dividido la fuerza inicial aplicada.
	float frictionForce = ball.mass / initialForce;

	bool appliedForce = false;


	InitWindow(windowWidth, windowHeight, windowTitle.c_str());


	while (!WindowShouldClose()) // Condición que permite cerrar la ventana.
	{
		// Si se presionó la barra espaciadora al estar quieta la bola...
		if (IsKeyPressed(KEY_SPACE) && !appliedForce)
		{
			// Se le aplica la fuerza.
			appliedForce = true;
			ballSpeedY = torque;
		}

		// Si la fuerza se le fue aplicada...
		if (appliedForce)
		{
			// Se mueve la pelota con la velocidad actual.
			ball.y += ballSpeedY * GetFrameTime();

			// A la velocidad se le resta la fricción.
			ballSpeedY -= frictionForce;

			// Si la velocidad actual pasó a ser negativa (en sentido contrario)...
			if (ballSpeedY < 0.0f)
			{
				// Se setea a 0 y se notifica que no hay una fuerza aplicándose sobre la bola.
				ballSpeedY = 0.0f;
				appliedForce = false;
			}
		}
		
		cout << ballSpeedY << endl; // Testeo para comprobar el cambio de velocidad.


		BeginDrawing();
		ClearBackground(BLACK);

		DrawCircle((int)ball.x, (int)ball.y, ball.radius, LIGHTGRAY); // La bola que va a recibir el impulso.
		DrawCircle(160, 60, 10, WHITE); // El círculo de la esquina superior izquierda.

		DrawRectangleLines(150, 50, 600, 800, WHITE); // El rectángulo que simula ser la mesa.

		EndDrawing();
	}


	return 0;
}
