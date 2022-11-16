#ifndef BALL_H
#define BALL_H

#include "raylib.h"


struct BALL
{
	Vector2 position;

	bool inMovement;
	float radius;
	float mass;

	float angle;
	Vector2 vectorDirection;
	Vector2 speed;
	Color color;

	float receivedInitialForce;
};


BALL createBall(float x, float y, float radius, float mass, Color color = WHITE); // Crea la bola con los valores pasados por parámetro.

void updateBall(BALL& ball); // Actualiza el estado de la bola. Esta función debe llamarse siempre.
void setSpeedBall(BALL& ball, Vector2 originForcePosition, float force); // Establece una nueva velocidad a la bola. Pisa la velocidad anterior.
void addSpeedBall(BALL& ball, Vector2 speed, float force); // Modifica la velocidad actual de la bola. Se le suma a la velocidad actual.

void drawBall(BALL ball); // Dibuja la bola.


#endif // !BALL_H
