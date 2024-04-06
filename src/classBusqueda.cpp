#include "classBusqueda.h"
#include "Manejador.h"
#include "definitions.h"

//std::mutex mtx;
Busqueda::Busqueda(int id, int ini, int fin, int line, std::string pal, std::string p_a, std::string p_p)
            : idHilo(id), inicio(ini), final(fin), linea(line), palabra(pal), palabra_ant(p_a), palabra_post(p_p){};


void Busqueda::toString() const
{
    std::cout << "[Hilo " << idHilo+1 << " inicio:" << inicio+1 << " - "
    << "final: " << final+1 << "]"
    << " :: "
    << "línea " << linea+1 << " :: "
    << "... " << palabra_ant << " " << palabra << " "
    << palabra_post << " ..." << std::endl;
} 
