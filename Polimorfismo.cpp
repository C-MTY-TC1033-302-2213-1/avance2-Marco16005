// A00839451
// Marco Antonio Torres Ramirez 
// ITC
// 23/05/2024
 

#include "Polimorfismo.h"


using namespace std;

// - Inicializa el arreglo de apuntadores a nullptr
Polimorfismo::Polimorfismo() {
    for (int index = 0; index < MAX_VIDEOS; index++){
        arrPtrVideos[index] = nullptr;
    }

    cantidad = 0;
}

// - Validar que existe ese video en la posición index
// - si si existe se modifica esa posición del arreglo de apuntadores
// y se le asigna el apuntador recibido como parámetro de entrada
// - Si no existe no se modifica el arreglo de apuntadores.
void Polimorfismo::setPtrVideo(int index, Video *video){
    if (index >= 0 && index < cantidad){
        arrPtrVideos[index] = video;
    }
}

// - cambia el valor del atributo cantidad
// - validar que cantidad este entre 0 .. MAX_VIDEOS,
// - de lo contrario NO se modifica el valor del cantidad
void Polimorfismo::setCantidad(int _cantidad){
    if (_cantidad >= 0 && _cantidad <= MAX_VIDEOS){
        cantidad = _cantidad;
    }
}

// - retorna el apuntador que esta en la posición indicada en index
// - el método debe validar que exista index en el arreglo de apuntadores
Video* Polimorfismo::getPtrVideo(int index){
    if (index >= 0 && index < cantidad){
        return arrPtrVideos[index];
    }
    else{
        return nullptr;
    }
}

//- retorna el atributo cantidad
int Polimorfismo::getCantidad(){
    return cantidad;
}

// Despliega la información de todas las series y peliculas del arreglo
// usando el método str() correspondiente al tipo del apuntador,
// al final despliega
// Peliculas = ##
// Series = ##
void Polimorfismo::reporteInventario(){
    int cantidadSeries = 0, cantidadPeliculas = 0;
    for (int index = 0; index < cantidad; index++){
        cout << arrPtrVideos[index]->str() << endl;
        if (typeid(*arrPtrVideos[index]) == typeid(Serie)){
            cantidadSeries++;
        }
        else if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)){
            cantidadPeliculas++;
        }
    }
    cout << "Peliculas = " << cantidadPeliculas << endl;
    cout << "Series = " << cantidadSeries << endl;
}

// Despliega la información de todas las Series y Peliculas que tienen
// la calificación indicada en el parámetro de entrada,
// al final despliega la cantidad con el siguiente mensaje (ver casos de prueba).
// Total = ##
void Polimorfismo::reporteCalificacion(double _calificacion){
    int total = 0;
    for (int index = 0; index < cantidad; index++){
        if (arrPtrVideos[index]->getCalificacion() == _calificacion){
            cout << arrPtrVideos[index]->str() << endl;
            total++;
        }
    }
    cout << "Total = " << total << endl;
}

// Despliega la información de todas las Series y Peliculas que
// tienen el genero indicado en el parámetro de entrada,
// al final despliega la cantidad que cumplio (ver casos de prueba).
// Total = ##
void Polimorfismo::reporteGenero(string _genero){
    int total = 0;
    for (int index = 0; index < cantidad; index++){
        if (arrPtrVideos[index]->getGenero() == _genero){
            cout << arrPtrVideos[index]->str() << endl;
            total++;
        }
    }
    cout << "Total = " << total << endl;

}

// Despliega la información de todas las Peliculas que existan en el arreglo,
// al final despliega la cantidad en existencia.
// Total Peliculas = ##
// en caso de que no existan peliculas debe
// desplegar No peliculas con salto de línea al final(ver casos de prueba)
void Polimorfismo::reportePeliculas(){
    int total = 0;
    for (int index = 0; index < cantidad; index++){
        if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)){
            cout << arrPtrVideos[index]->str() << endl;
            total++;
        }
    }
    if (total == 0){
        cout << "No peliculas" << endl;
    }
    else{
        cout << "Total Peliculas = " << total << endl;
    }
}

// Despliega todos las Series que existan en el arreglo,
// al final despliega la cantidad en existencia.
// Total Series = ##
// en caso de que no existan Series debe
// desplegar No series con salto de línea al final
void Polimorfismo::reporteSeries(){
    int total = 0;
    for (int index = 0; index < cantidad; index++){
        if (typeid(*arrPtrVideos[index]) == typeid(Serie)){
            cout << arrPtrVideos[index]->str() << endl;
            total++;
        }
    }
    if (total == 0){
        cout << "No series" << endl;
    }
    else{
        cout << "Total Series = " << total << endl;
    }
}

// función que lee el archivo de entrada y crea los objetos de tipo Serie, Pelicula y Episodio.
void Polimorfismo::leerArchivo(string nombre) {
    Serie *arrPtrSeries[50];
    Pelicula *arrPtrPeliculas[50];
    Episodio episodio;
    fstream entrada;
    string row[7];
    string line, word;
    int cantidadSeries = 0;
    int cantidadPeliculas = 0;
    int iR = 0;
    double promedio;

    entrada.open(nombre, ios::in);

    // Leer el archivo
    while (getline(entrada, line)) {
        stringstream s(line);
        iR = 0;

        // Leer cada palabra de la línea
        while (getline(s, word, ',')) {
            row[iR] = word;
            iR++;
        }

        // Crear los objetos de tipo Serie, Pelicula y Episodio
        if (row[0] == "S") {
            arrPtrSeries[cantidadSeries] = new Serie(row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6]));
            cantidadSeries++;
        } else if (row[0] == "P") {
            arrPtrPeliculas[cantidadPeliculas] = new Pelicula(row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6]));
            cantidadPeliculas++;
        } else if (row[0] == "E") {
            int indexi = stoi(row[1]) - 500;
            arrPtrSeries[indexi]->agregaEpisodio(*new Episodio(row[2], stoi(row[3]), stoi(row[4])));
        }
    }

    // Calcular el promedio de las series, asignar la calificación y calcular la duración, y asignar los apuntadores de las series y peliculas al arreglo de apuntadores de videos
    for (int index = 0; index < cantidadSeries; index++) {
        promedio = arrPtrSeries[index]->calculaPromedio();
        arrPtrSeries[index]->setCalificacion(promedio);
        arrPtrSeries[index]->calcularDuracion();
        arrPtrVideos[cantidad] = arrPtrSeries[index];
        cantidad++;
    }

    for (int index = 0; index < cantidadPeliculas; index++) {
        arrPtrVideos[cantidad] = arrPtrPeliculas[index];
        cantidad++;
    }

    // for (int index = 0; index < cantidad; index++) {
    //     cout << index << " " << arrPtrVideos[index]->str() << endl;
    // }

    entrada.close();
}