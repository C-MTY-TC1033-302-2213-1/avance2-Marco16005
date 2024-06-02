// A00839451
// Marco Antonio Torres Ramirez 
// ITC
// 23/05/2024
// Durante este entrgable pude aprender a usar el polimorfismo para llamar a funciones específicas de cada clase derivada, a pesar de que se llamen de la misma 
//forma. Ademas de esto, pude aprender a usar el typeid para comparar los tipos de datos de los objetos y a usarlo para llamar a funciones específicas de cada clase 
//derivada. Finalmente, pude aprender a usar el typeid para comparar los tipos de datos de los objetos y a usarlo para llamar a funciones específicas de cada clase 
//derivada.

const int MAX_VIDEOS = 100;

#ifndef Polimorfismo_h
#define Polimorfismo_h

#include <iostream>
#include <typeinfo>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
#include "Serie.h"
#include "Episodio.h"
#include "Pelicula.h"
#include "Video.h"

using namespace std;

class Polimorfismo {
private:
    Video *arrPtrVideos[MAX_VIDEOS];
    int cantidad;
    
public:
    Polimorfismo();

    void leerArchivo(string nombre);

    void setPtrVideo(int index, Video *video);
    void setCantidad(int _cantidad);

    Video* getPtrVideo(int index);
    int getCantidad();

    void reporteInventario();
    void reporteCalificacion(double _calificacion);
    void reporteGenero(string _genero);
    void reportePeliculas();
    void reporteSeries();

};
#endif /* Polimorfismo_h */