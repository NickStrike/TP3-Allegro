#include "Bala.h"
Bala::Bala()
{
	x = -10;
	y = -10;
	shot = false;
}
Bala::~Bala()
{
}
void Bala::disparo(float X_juga, float Y_juga, float H_juga, float W_juga, float xSpd, float ySpd)
{
	if (shot = false)
	{
		x = X_juga + W_juga / 2;
		y = Y_juga + H_juga / 2;
		shot = true;
		xSpeed = xSpd;
		ySpeed = xSpd;
	}
}
bool Bala::outBounds(float width_pantalla, float height_pantalla) 
{
	if (x<0 || x>width_pantalla || y<0 || y>height_pantalla)
	{
		shot = false;
		xSpeed = 0;
		ySpeed = 0;
		x = -10;
		y = -10;
	}
	
	return shot;
}
bool Bala::colisionEnemigo(float W_enemy, float H_enemy,
	float X_enemy, float Y_enemy) 
{
	
	if ((Y_enemy + H_enemy > y && y > Y_enemy && x >= X_enemy && x <= X_enemy + W_enemy)
		|| (Y_enemy + H_enemy > y && y > Y_enemy && x + w >= X_enemy && x + w <= X_enemy + W_enemy))
	{
		cout << "abajo" << endl;
		shot = false;
		xSpeed = 0;
		ySpeed = 0;
		x = -10;
		y = -10;
		return true;
	}
	if ((x > X_enemy && x<X_enemy + W_enemy && y > Y_enemy && y < Y_enemy + H_enemy)
		|| (x > X_enemy && x < X_enemy + W_enemy && y + w > Y_enemy && y + w < Y_enemy + H_enemy))
	{
		cout << "Derecha" << endl;
		shot = false;
		xSpeed = 0;
		ySpeed = 0;
		x = -10;
		y = -10;
		return true;
	}
	if ((x > X_enemy - W_enemy && x<X_enemy && y > Y_enemy && y < Y_enemy + H_enemy)
		|| (x > X_enemy - W_enemy && x < X_enemy  && y + w > Y_enemy && y + w < Y_enemy + H_enemy))
	{
		cout << "izquierda" << endl;
		shot = false;
		xSpeed = 0;
		ySpeed = 0;
		x = -10;
		y = -10;
		return true;
	}
	if (y + h > Y_enemy && y + h < Y_enemy + H_enemy && x > X_enemy && x < X_enemy + W_enemy
		|| y + h > Y_enemy && y + h < Y_enemy + H_enemy && x + w > X_enemy && x + w < X_enemy + W_enemy)
	{
		cout << "Arriba" << endl; 
		shot = false;
		xSpeed = 0;
		ySpeed = 0;
		x = -10;
		y = -10;
		return true;
	}
	return false;

}
bool Bala::getShot() {
	return shot;
}
