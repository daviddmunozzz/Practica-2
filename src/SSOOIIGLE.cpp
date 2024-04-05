#include "definitions.h"
#include "Busqueda.h"
#include "Manejador.h"


std::queue<std::thread> colaHilos;

void CrearHilos (int numHilos, std::string libro, std::string palabra);

int main(int argc, char *argv[])
{
    if(argc < 4)
    {
        std::cout << "Error: Faltan argumentos. SSOOIIGLE <nombre_fichero> <palabra> <numero_hilos>" << std::endl;
        exit(EXIT_FAILURE);        
    }   

    std::string libro = argv[1];
    std::string palabra = argv[2];  
    int numHilos = atoi(argv[3]);

    CrearHilos(numHilos, libro, palabra);


    return 0;
}

void CrearHilos (int numHilos, std::string libro, std::string palabra)
{
    
    int inicio = 0;
    int fin = 0;
    int numLineas = ContarLineas(libro);
    int fragmento = numLineas / numHilos;

    for(int idHilo = 0; idHilo < numHilos; idHilo++)
    {
        inicio = idHilo * fragmento;
        fin = (inicio + fragmento) - 1;
        if(idHilo == numHilos - 1) fin = numLineas - 1;

        Busqueda b(idHilo, inicio, fin, libro, palabra);
        colaHilos.push(std::thread(b));    
    }

    while(!colaHilos.empty())
    {
        colaHilos.front().join();
        colaHilos.pop();
    }
}

