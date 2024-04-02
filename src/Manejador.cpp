#include "Manejador.h"

int ContarLineas(std::string nombreFichero)
{
    std::ifstream file(nombreFichero);
    int contador = 0;
    std::string linea;

    while (std::getline(file, linea))
    {
        contador++;
    }

    return contador;
}

std::vector<std::string> LeerFichero(std::string libro)
{
    std::ifstream file(libro);
    std::vector<std::string> lineas;
    std::string linea;

    while (std::getline(file, linea))
    {
        lineas.push_back(linea);
    }

    return lineas;
}

std::string toLower(std::string str)
{
    std::string strLower = str;
    std::transform(strLower.begin(), strLower.end(), strLower.begin(), [](unsigned char c){
        return std::tolower(c);
    });
    return strLower;
}

std::vector<std::string> split(std::string str, std::string patron)
{
    int posInicio = 0;
    int posEncontrada = 0;
    std::string splitted;
    std::vector<std::string> resultados;
    
    while(posEncontrada >= 0){
        posEncontrada = str.find(patron, posInicio);
        splitted = str.substr(posInicio, posEncontrada - posInicio);
        posInicio = posEncontrada + 1;
        resultados.push_back(splitted);
    }
    
    return resultados;
}