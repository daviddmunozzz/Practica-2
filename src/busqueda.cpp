#include "busqueda.h"
#include <iostream>

Busqueda::Busqueda(int id, int ini, int fin, std::string libro) : idHilo(id), inicio(ini), final(fin) {}

void Busqueda::operator()() const
{
    hacerBusqueda();
}
    
void Busqueda::hacerBusqueda() const
{
    
} 

void Busqueda::toString()
{
    std::cout << "[Hilo " << idHilo << " inicio:" << inicio << " - " << "final: " << final << "]" << 
    " :: " << "línea " << linea << " :: " << "... " << palabra_ant << " " << palabra << " "
    << palabra_post << " ..." << std::endl;
}