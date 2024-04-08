#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <vector>
#include <string>

class Busqueda {
private:
    int idHilo;
    int inicio;
    int final;
    std::string libro;

public:
    Busqueda(int id, int ini, int fin, std::string lib);
    
    void operator()() const;                                    // Operador de llamada de función para ejecutar el hilo

    void hacerBusqueda(std::vector<std::string> texto) const;   // Método para realizar la búsqueda en el rango de líneas dado

    void toString();                                            // Método para imprimir información sobre la búsqueda realizada por el hilo
};

#endif /* BUSQUEDA_H */
