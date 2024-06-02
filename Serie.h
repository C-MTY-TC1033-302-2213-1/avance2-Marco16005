// A00839451
// Marco Antonio Torres Ramirez 
// ITC
// 20/05/2024
// Durante este entregable, me fue posible aprender a a asegurarme de que los métodos cumplen con la funcionalidad esperada y a mantener el diseño consistente 
//con el UML. Además, pude aprender a implementar la herencia y a utilizarla para extender las funcionalidades de las clases. También, pude aprender a utilizar 
//la clase padre para acceder a los atributos de la clase hija. Finalmente, pude aprender a utilizar la clase padre para acceder a los atributos de la clase hija.

#ifndef SERIE_H
#define SERIE_H

#include "Video.h"
#include "Episodio.h"
#include <string>
#include <iostream>

using namespace std;

class Serie : public Video {
private:
    Episodio episodios[5];
    int cantidad;

public:
    // Metodos constructores
    Serie();
    Serie(string _id, string _titulo, int _duracion, string _genero, double _calificacion, int _cantidad);

    //Metodos modificadores - Setter
    void setEpisodio(Episodio episodio, int posicion);
    void setCantidad(int _cantidad);

    //Metodos de acceso - Getter
    Episodio getEpisodio(int posicion);
    int getCantidad();

    //Otros metodos
    void calcularDuracion();

    double calculaPromedio();
    string str();
    
    void agregaEpisodio(Episodio episodio);
};

#endif // SERIE_H