#include "hiloBuscador.h"
#include "manejadorFicheros.h"
#include <iostream>

Busqueda::Busqueda(int id, int ini, int fin, std::string lib) : idHilo(id), inicio(ini), final(fin), libro(lib) {};

void Busqueda::operator()() const
{
    std::vector<std::string> texto = LeerFichero(libro);
    hacerBusqueda(texto);
}
    
void Busqueda::hacerBusqueda(std::vector<std::string> texto) const
{
    for(int linea = inicio; linea <= final; linea++)
    {
        std::string textoHilo = texto[linea];
    }
} 

void Busqueda::toString()
{
    std::cout << "[Hilo " << idHilo << " inicio:" << inicio << " - " << "final: " << final << "]" << 
    " :: " << "línea " << linea << " :: " << "... " << palabra_ant << " " << palabra << " "
    << palabra_post << " ..." << std::endl;
}