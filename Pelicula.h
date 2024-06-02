// A00839451
// Marco Antonio Torres Ramirez 
// ITC
// 20/05/2024

#ifndef PELICULA_H
#define PELICULA_H

#include <string>
#include <iostream>
#include "Video.h"

using namespace std;

class Pelicula : public Video{
private: 
    int oscares;

public:
// Constructores: vacio y con parametros
    Pelicula();
    Pelicula(string _id, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares);

    //Metodo de acceso - Getter
    int getOscares();

    //Metodo modificador - Setter
    void setOscares(int _oscares);

    //Metodo para convertir a string
    string str();
};

#endif // PELICULA_H