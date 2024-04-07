#include <iostream>
#include <thread>
#include <filesystem>
#include <vector>
#include <iostream>
#include <mutex>
#include <queue>
#include "classBusqueda.h"
#include "Manejador.h"


void CrearHilos (int numHilos, std::string libro, std::string palabra);
void Buscar (int idHilo, int inicio, int fin, std::string libro, std::string palabra);
void Imprimir ();

std::vector<std::queue<Busqueda>> vEncontrados;
std::mutex mtx;

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

    vEncontrados.resize(numHilos);
    CrearHilos(numHilos, libro, palabra);

    Imprimir();


    return 0;
}

void CrearHilos (int numHilos, std::string libro, std::string palabra)
{
    std::queue<std::thread> colaHilos;
    
    int inicio = 0;
    int fin = 0;
    int numLineas = ContarLineas(libro);
    int fragmento = numLineas / numHilos;

    for(int idHilo = 0; idHilo < numHilos; idHilo++)
    {
        inicio = idHilo * fragmento;
        fin = (inicio + fragmento) - 1;
        if(idHilo == numHilos - 1) fin = numLineas - 1;
        colaHilos.push(std::thread(Buscar, idHilo, inicio, fin, libro, palabra));    
    }

    while(!colaHilos.empty())
    {
        colaHilos.front().join();
        colaHilos.pop();
    }
}


void Buscar (int idHilo, int inicio, int fin, std::string libro, std::string palabra)
{
    std::vector<std::string> fragmento = LeerFichero(libro);
    std::queue<Busqueda> colaEncontrados;
    std::string palabra_ant, palabra_post;

    std::lock_guard<std::mutex> lock(mtx);
    for(int linea = inicio; linea <= fin; linea++)
    {
        std::string textoLinea = fragmento[linea];
        std::vector<std::string> lineaSeparada = split(textoLinea, " ");

        for(int i=0; i<lineaSeparada.size(); i++)
        {
            if(toLower(lineaSeparada[i]) == toLower(palabra))
            {
                if(i == 0 && lineaSeparada.size() == 1)
                {
                    palabra_ant = "";
                    palabra_post = "";
                }else if(i == 0)
                {
                    palabra_ant = "";
                    palabra_post = lineaSeparada[i+1];                
                }else if(i == lineaSeparada.size() - 1)
                {
                    palabra_ant = lineaSeparada[i-1];
                    palabra_post = "";  
                }else
                {
                    palabra_ant = lineaSeparada[i-1];
                    palabra_post = lineaSeparada[i+1];  
                }       
                Busqueda b = Busqueda(idHilo, inicio, fin, linea, palabra, palabra_ant, palabra_post);
                colaEncontrados.push(b);          
            }   
        }
    }  
    vEncontrados[idHilo] = colaEncontrados;
}

void Imprimir ()
{
    for(int i=0; i<vEncontrados.size(); i++)
    {
        while(!vEncontrados[i].empty())
        {
            vEncontrados[i].front().toString();
            vEncontrados[i].pop();
        }
    }
}