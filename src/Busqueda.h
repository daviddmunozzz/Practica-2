#include <string>
#include <vector>

#ifndef BUSQUEDA
#define BUSQUEDA
class Busqueda
{
    public:
        Busqueda(int id, int ini, int fin, std::string libro, std::string palabra);
        void operator()() const;    
        void toString() const;
    private:
        void hacerBusqueda(std::vector<std::string> texto) const;
        void setAnterior_Posterior(std::vector<std::string> lineaSeparada);
        void setAnterior(std::string anterior);
        void setPosterior(std::string posterior);
        int idHilo;
        int inicio;
        int final;
        std::string libro;   
        int linea;
        std::string palabra;
        std::string palabra_ant;
        std::string palabra_post;        
};
#endif