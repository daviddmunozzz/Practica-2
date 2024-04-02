#include "definitions.h"
#include "manejadorFicheros.h"
#include "hiloBuscador.h"


using namespace std;
int main(int argc, char *argv[])
{
    if(argc < 4)
    {
        std::cout << "Error: Faltan argumentos. SSOOIIGLE <nombre_fichero> <palabra> <numero_hilos>" << std::endl;
        exit(EXIT_FAILURE);
    } 
    //Variables
    string nombre_archivo;
    int numero_hilos = 0, lineas_por_hilo = 0;
    vector<std::thread> hilos;


    cout << "Introduce el nombre del archivo: ";   //Solicitamos el nombre del archivo
    cin >> nombre_archivo;
    
    cout << "Introduce el número de hilos: ";      //Solicitamos el numero de hilos
    cin >> numero_hilos;

                                                           // Definimos los parámetros para la búsqueda en hilos
    int num_lineas_totales = ContarLineas(nombre_archivo);
    lineas_por_hilo = num_lineas_totales / numero_hilos;

                                                          // Creamos los hilos y los almacenamos en el vector
    for (int i = 0; i < numero_hilos; ++i) {
        int inicio = i * lineas_por_hilo;
        int fin = inicio + lineas_por_hilo - 1;
        Busqueda hilo(i, inicio, fin, nombre_archivo);
        hilos.push_back(std::thread(hilo));
    }

                                                           / Esperamos a que todos los hilos terminen su ejecución
    for (auto& hilo : hilos) {
        hilo.join();
    } 
}

