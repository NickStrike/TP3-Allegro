#include <cstdlib>
//Incluimos las funciones b�sicas de Allegro
//#include <allegro5/allegro.h>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
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
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP  *jugador1 = NULL;
	
	//  Inicia allegro5, esto es necesario para realizar cualquier
	//  funci�n de allegro
	al_init();

	if (!al_init()) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize allegro!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}
	if (!al_init_image_addon()) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}
	display = al_create_display(800, 600);

	if (!display) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}

	jugador1 = al_load_bitmap("../Sprite/JugadoOP1.png");

	if (!jugador1) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}

	//game loop
	while (!gameOver) {
		//  La siguiente funci�n limpia el buffer, con un color determinado, 
		//  recibe como par�metro un ALLEGRO_COLOR. 
		//  La funci�n al_map_rgb(0,0,0) recibe como tres enteres sin signo,
		//  cada uno determina la cantidad del color rojo, verde y azul
		//  respectivamente; esta funci�n devuelve un ALLEGRO_COLOR con lo
		//  que encaja perfecto con el par�metro que recibe la funci�n
		//  al_clear_to_color(...)
		al_clear_to_color(al_map_rgb(0, 0, 0));

		al_draw_bitmap(jugador1, 200, 200, 0);// me lo pociciona siempre en el 200 200 fijarse de poner dos variables para poder movel al personaje

		//  Intercambia los buffers, ahora la ventana mostrar� tendr� fondo
		//  de color negro. Si minimiza la ventana y la vuelve restaurar, se
		//  dar� cuenta que ahora la pantalla muestra lo que estuve detr�s.
		//  Esto es porque el buffer ahora tiene lo que estaba detr�s de la
		//  ventana. Luego veremos como redibujar la ventana cuando se realice
		//  un evento.
		al_flip_display();
	}
	//  No olvidarnos de eliminar el contenido bajo el puntero de ventana,
	//  esto eliminar� a la ventana de la memoria.
	al_destroy_display(display);
	al_destroy_bitmap(jugador1);
	return 0;
}
