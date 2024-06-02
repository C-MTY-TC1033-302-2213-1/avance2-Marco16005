// A00839451
// Marco Antonio Torres Ramirez 
// ITC
// 20/05/2024

#include "Serie.h"

using namespace std;

// Metodos constructores
Serie::Serie():Video(){
    // Solo se inicializa la cantidad de episodios
    cantidad = 0;
}

Serie::Serie(string _id, string _titulo, int _duracion, string _genero, double _calificacion, int _cantidad):Video(_id, _titulo, _duracion, _genero, _calificacion){
    // Se inicializa la cantidad de episodios
    cantidad = _cantidad;
}

//Metodos modificadores - Setter
void Serie::setEpisodio(Episodio episodio, int posicion){
    // Validar que exista el episodio
    if (posicion < cantidad && posicion >= 0){
        episodios[posicion] = episodio;
    }
    else{
        cout << "No se puede agregar el episodio" << endl;
    }
}

// Cambiar la cantidad de episodios con el nuevo valor
void Serie::setCantidad(int _cantidad){
    cantidad = _cantidad;
}

//Metodos de acceso - Getter
Episodio Serie::getEpisodio(int posicion){
    // Se crea un episodio vacio para retornarlo en caso de que no exista el episodio solicitado
    Episodio epi;

    // Validar que exista el episodio solicitado
    if (posicion < cantidad && posicion >= 0){
        return episodios[posicion];
    }
    else{
        cout << "No se puede obtener el episodio" << endl;
        return Episodio();
    }
}

// Obtener la cantidad de episodios
int Serie::getCantidad(){
    return cantidad;
}

//Otros metodos
double Serie::calculaPromedio(){
    double acum = 0.0;

    // Sumar todas las calificaciones de los episodios
    for (int index = 0; index < cantidad; index++){
        acum += episodios[index].getCalificacion();
    }

    //Validar que tenga episodios
    if (cantidad > 0){
        return acum / cantidad;
    } else {
        return 0;
    }
}

void Serie::calcularDuracion(){
    int totalDuracion = 0;
    for(int index = 0; index < cantidad; index++) {
        totalDuracion += episodios[index].getTemporada();
    }
    duracion = totalDuracion;
}


string Serie::str(){
    string str = Video::str() + " " + to_string(cantidad) + "\n";
    for (int index = 0; index < cantidad; index++){
        str += episodios[index].str() + "\n";
    }
    return str;
}
    
void Serie::agregaEpisodio(Episodio episodio){
    // Validar que no se exceda el limite de episodios
    if (cantidad < 5){
        episodios[cantidad++] = episodio;
    }
    else{
        cout << "No se puede agregar el episodio" << endl;
    }
}