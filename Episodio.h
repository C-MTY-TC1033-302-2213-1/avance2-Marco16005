// A00839451
// Marco Antonio Torres Ramirez 
// ITC
// 20/05/2024

#ifndef EPISODIO_H
#define EPISODIO_H

#include <string>
using namespace std;

class Episodio {
private:
    string titulo;
    int temporada;
    int calificacion;
    int duracion1;

public:
    Episodio();
    Episodio(string _titulo, int _temporada, int _calificacion);

    string getTitulo();
    int getTemporada();
    int getCalificacion();
    int getDuracion1();

    void setTitulo(string _titulo);
    void setTemporada(int _temporada);
    void setCalificacion(double _calificacion);

    string str();
};

#endif // EPISODIO_H
