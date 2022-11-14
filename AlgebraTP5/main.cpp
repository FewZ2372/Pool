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
	string windowTitle = "pool"; // T�tulo de la ventana.

	float ballSpeedY = 0.0f; // La velocidad de movimiento de la bola. Se actualiza en tiempo de ejecuci�n.

	float initialForce = 15.0f; // La fuerza que se le va a dar con el taco.
	float torque = initialForce * ball.radius; // La fuerza que recibe la bola (fuerza angular). La f�rmula de la
											   // fuerza angular es la fuerza inicial por el radio.

	// El rozamiento est�tico es igual a la masa dividido la fuerza inicial aplicada.
	float frictionForce = ball.mass / initialForce;

	bool appliedForce = false;


	InitWindow(windowWidth, windowHeight, windowTitle.c_str());


	while (!WindowShouldClose()) // Condici�n que permite cerrar la ventana.
	{
		// Si se presion� la barra espaciadora al estar quieta la bola...
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

			// A la velocidad se le resta la fricci�n.
			ballSpeedY -= frictionForce;

			// Si la velocidad actual pas� a ser negativa (en sentido contrario)...
			if (ballSpeedY < 0.0f)
			{
				// Se setea a 0 y se notifica que no hay una fuerza aplic�ndose sobre la bola.
				ballSpeedY = 0.0f;
				appliedForce = false;
			}
		}
		
		cout << ballSpeedY << endl; // Testeo para comprobar el cambio de velocidad.


		BeginDrawing();
		ClearBackground(BLACK);

		DrawCircle((int)ball.x, (int)ball.y, ball.radius, LIGHTGRAY); // La bola que va a recibir el impulso.
		DrawCircle(160, 60, 10, WHITE); // El c�rculo de la esquina superior izquierda.

		DrawRectangleLines(150, 50, 600, 800, WHITE); // El rect�ngulo que simula ser la mesa.

		EndDrawing();
	}


	return 0;
}
