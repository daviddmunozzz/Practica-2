#include <string>

#ifndef BUSQUEDA
#define BUSQUEDA
class Busqueda
{
    public:
        Busqueda(int id, int ini, int fin, std::string libro);
        void operator()() const;
        void toString();
    private:
        void hacerBusqueda() const;
        int idHilo;
        int inicio;
        int final;
        int linea;
        std::string palabra;
        std::string palabra_ant;
        std::string palabra_post;
};
#endif