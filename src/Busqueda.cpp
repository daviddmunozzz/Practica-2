#include "Busqueda.h"
#include "Manejador.h"
#include "definitions.h"

std::mutex mtx;
Busqueda::Busqueda(int id, int ini, int fin, std::string lib, std::string pal) : idHilo(id), inicio(ini), final(fin), libro(lib), palabra(pal){};
std::queue<Busqueda> colaEncontrados;

void Busqueda::operator()() const
{
    std::vector<std::string> texto = LeerFichero(libro);
    hacerBusqueda(texto);
    toString();
}

void Busqueda::setAnterior(std::string anterior)
{
    palabra_ant = anterior;
}

void Busqueda::setPosterior(std::string posterior)
{
    palabra_post = posterior;
}

void Busqueda::hacerBusqueda(std::vector<std::string> texto) const
{

    std::vector<std::string> lineaSeparada;

    std::lock_guard<std::mutex> lock(mtx);
    for (int linea = inicio; linea <= final; linea++)
    {
        Busqueda b = Busqueda(idHilo, inicio, final, libro, palabra);
        std::string textoHilo = texto[linea];
        lineaSeparada = split(textoHilo, " ");

        b.setAnterior_Posterior(lineaSeparada);

        colaEncontrados.push(b);
    }
}

void Busqueda::setAnterior_Posterior(std::vector<std::string> lineaSeparada)
{
    int lineaSize;
    std::string encontrada;

    for (int i = 0; i < lineaSeparada.size(); i++)
    {
        if (lineaSeparada[i] == palabra)
        {
            encontrada = lineaSeparada[i];
            lineaSize = lineaSeparada.size();

            if (i == 0 && lineaSize == 1)
            {
                setAnterior("");
                setPosterior("");
            }
            else if (i == 0)
            {
                setAnterior("");
                setPosterior(lineaSeparada[i + 1]);
            }
            else if (i == lineaSize - 1)
            {
                setAnterior(lineaSeparada[i - 1]);
                setPosterior("");
            }
            else
            {
                setAnterior(lineaSeparada[i - 1]);
                setPosterior(lineaSeparada[i + 1]);
            }
        }
    }
}

void Busqueda::toString() const
{
    while(!colaEncontrados.empty()){
        Busqueda b = colaEncontrados.front();
        std::cout << "[Hilo " << idHilo << " inicio:" << inicio << " - "
            << "final: " << final << "]"
            << " :: "
            << "línea " << linea << " :: "
            << "... " << palabra_ant << " " << palabra << " "
            << palabra_post << " ..." << std::endl;
        colaEncontrados.pop();
    }   
}