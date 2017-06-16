#include<iostream>
#include<time.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>
#include<allegro.h>
#include<fstream>

int w = 1600;
int h = 100;

int can =  10;
using namespace std;
#include "validaciones.h"
#include "algoritmos_lista.h"
#include "algoritmos_juego.h"

clock_t t_maq_ini, t_maq_fin, t_per_ini, t_per_fin;
double secs, secs_persona;

int main(){
    crear_fichas();

    allegro_init();
    install_keyboard();
    set_color_depth(16);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, w, h, 0, 0);
    cout<<"Ficha principal: ";
    cout<<principal->pintaIzquierda<<" | "<<principal->pintaDerecha<<endl;
    leer_Imagenes();
    //mostrar_imagenes();
    cambiar_sentido();

    jugar();

    imprimir();
    verificar_partida();
    t_maq_fin = clock();
	secs = (double)(t_maq_fin - t_maq_ini) / CLOCKS_PER_SEC;
	cout<<endl<<"TIEMPO DE JUEGO MAQUINA: "<<secs <<endl;
	system("pause");
	system("cls");

	cout<<"Ficha De Salida: ";
    cout<<"[ "<<principal->pintaIzquierda<<" | "<<principal->pintaDerecha<<" ]"<<endl;
	cambiar_estado();
	jugar_persona();
	verificar_partida();
	t_per_fin = clock();
	secs_persona = (double) (t_per_fin - t_per_ini) / CLOCKS_PER_SEC;
	cout<<endl<<"TIEMPO DE JUEGO PERSONA: "<<secs_persona <<endl;
	cout<<endl<<"TIEMPO DE JUEGO MAQUINA: "<<secs <<endl;
}



