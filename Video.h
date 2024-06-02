// A00839451
// Marco Antonio Torres Ramirez 
// ITC
// 20/05/2024

#ifndef VIDEO_H
#define VIDEO_H

#include <string>
using namespace std;

class Video {
    // Atributos de la clase Video
protected:
    string id;
    string titulo;
    int duracion;
    string genero;
    double calificacion;

public:
    // Constructores
    Video();
    Video(string _id, string _titulo, int _duracion, string _genero, double _calificacion);

    // Getters
    string getId();
    string getTitulo();
    int getDuracion();
    string getGenero();
    double getCalificacion();

    // Setters
    void setId(string _id);
    void setTitulo(string _titulo);
    void setDuracion(int _duracion);
    void setGenero(string _genero);
    void setCalificacion(double _calificacion);

    virtual string str();
};

#endif // VIDEO_H
