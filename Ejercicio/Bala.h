#ifndef BALA_H
#define BALA_H
#include "Jugador.h"
class Bala
{
private:
	float x;
	float y;
	float w;
	float h;
	float xSpeed;
	float ySpeed;
	bool shot;
public:
	Bala();
	~Bala();
	void disparo(float X_juga, float Y_juga, float H_juga, float W_juga, float xSpd, float ySpd);
	bool outBounds(float width_pantalla, float height_pantalla);
	bool colisionEnemigo(float W_enemy, float H_enemy, 
				float X_enemy, float Y_enemy);
	bool getShot();
};
#endif

