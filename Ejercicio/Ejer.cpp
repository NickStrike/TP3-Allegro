#include <cstdlib>
//Incluimos las funciones b�sicas de Allegro
//#include <allegro5/allegro.h>
#include <iostream>
//#include "../allegro5/allegro.h"
#include <allegro5/allegro.h>
using namespace std;
void input() {
}
void update() {
}
void draw() {
}
void result() {
}
int main(int argc, char** argv) {
	bool gameOver = false;
	//  Crea un puntero a un ALLEGRO_DISPLAY
	ALLEGRO_DISPLAY* ventana;

	//  Inicia allegro5, esto es necesario para realizar cualquier
	//  funci�n de allegro
	al_init();

	//  al_create_display(640,480) crea un puntero a un ALLEGRO_DISPLAY
	//  y crea un ALLEGRO_DISPLAY de las dimensiones especificadas, en
	//  este caso 640 de ancho por 480 de alto
	ventana = al_create_display(640, 480);

	
	while (!gameOver) {

		//  La siguiente funci�n limpia el buffer, con un color determinado, 
		//  recibe como par�metro un ALLEGRO_COLOR. 
		//  La funci�n al_map_rgb(0,0,0) recibe como tres enteres sin signo,
		//  cada uno determina la cantidad del color rojo, verde y azul
		//  respectivamente; esta funci�n devuelve un ALLEGRO_COLOR con lo
		//  que encaja perfecto con el par�metro que recibe la funci�n
		//  al_clear_to_color(...)
		al_clear_to_color(al_map_rgb(0, 0, 0));


		//  Intercambia los buffers, ahora la ventana mostrar� tendr� fondo
		//  de color negro. Si minimiza la ventana y la vuelve restaurar, se
		//  dar� cuenta que ahora la pantalla muestra lo que estuve detr�s.
		//  Esto es porque el buffer ahora tiene lo que estaba detr�s de la
		//  ventana. Luego veremos como redibujar la ventana cuando se realice
		//  un evento.
		al_flip_display();

		//  Funci�n que recibe como par�metro un n�mero del tipo double, y que
		//  refiere a la cantidad de segundos que esperar� para pasar a la
		//  siguiente instrucci�n. En este caso luego de pasados dos segundos
		//  pasar� a return 0 con lo que se cerrar� la ventana.
		//al_rest(2);(instrucion comentada)
	}
	//  No olvidarnos de eliminar el contenido bajo el puntero de ventana,
	//  esto eliminar� a la ventana de la memoria.
	al_destroy_display(ventana);
	return 0;
}
