// A00839451
// Marco Antonio Torres Ramirez 
// ITC
// 20/05/2024

#include "Pelicula.h"

Pelicula::Pelicula(): Video(){
    oscares = 100;
}

Pelicula::Pelicula(string _id, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares) : Video(_id, _titulo, _duracion, _genero, _calificacion) {
    oscares = _oscares;
}

int Pelicula::getOscares() {
    return oscares;
}

string Pelicula::str() {
    // se tieneaccesso a los atributos de la clase padre dado que son protected
    return id + " " + titulo + " " + to_string(duracion) + " " + genero + " " + to_string(calificacion) + " " + to_string(oscares);
}
