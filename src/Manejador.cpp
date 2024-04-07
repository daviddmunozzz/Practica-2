/*********************************************************************
*
* Class Name: manejador.cpp
* Author/s name: David Muñoz y Daniel Aguado
* Release/Creation date: 6/4/2024
* Class version: 2.0
* Class description: Clase empleada cargar las lineas del libro en una
*                    cola y dividirla entre los hilos. Tambien cuenta
*                    las lineas del fichero.
*
**********************************************************************
*/

#include "Manejador.h"

/*********************************************************************
*
* Method name: contarLineas
*
* Description of the Method: Cuenta las lineas del fichero.
*
* Calling arguments: string nombreFichero --> Nombre del fichero a leer
*
* Return value:      int contador --> Numero de lineas
*
* Required Files: Requiere un fichero para leer.
*
*********************************************************************/
int contarLineas(std::string nombreFichero)
{
    std::ifstream file(nombreFichero);  //Apertura del fichero.
    int contador = 0;                   //Contador de lineas.
    std::string linea;                  //Variable linea usada para ver si esta vacia o no.

    while (std::getline(file, linea))   //Mientras la linea no sea vacia.
    {
        contador++;                     //Aumenta el contador.
    }

    file.close();                       //Cerramos el fichero.
    return contador;                    //Retorna el contador.
}


/*********************************************************************
*
* Method name: leerFichero
*
* Description of the Method: Almacena las lineas del fichero en una cola
*
* Calling arguments: string nombreFichero --> Nombre del fichero a leer
*
* Return value:      std::vector<std::string> lineas --> Vector de lineas del fichero
*
* Required Files: Requiere un fichero para leer.
*
*********************************************************************/
std::vector<std::string> leerFichero(std::string libro)
{
    std::ifstream file(libro);          //Apertura del fichero.
    std::vector<std::string> lineas;    //Vector en el que se almacena todas las lineas del fichero.
    std::string linea;                  //Linea en la que estamos actualmente.

    while (std::getline(file, linea))   //Bucle que se repite mientras haya lineas en el fichero.
    {
        lineas.push_back(linea);        //Encola lineas.
    }

    file.close();                       //Cerramos el fichero.
    return lineas;                      //Retorna lineas.
}

/*********************************************************************
*
* Method name: toLower
*
* Description of the Method: Convierte las letras en minusculas
*
* Calling arguments: std::string palabra--> Palabra a convertir en minuscula
*
* Return value:      std::string strLower --> Palabra en minuscula
*
*********************************************************************/
std::string toLower(std::string str)
{
    std::string strLower = str;
    std::transform(strLower.begin(), strLower.end(), strLower.begin(), [](unsigned char c)
                   { return std::tolower(c); });
    return strLower;
}

/*********************************************************************
*
* Method name: split
*
* Description of the Method: Divide la cola de lineas de fichero para que
*                            los hilos puedan trabajar en su parte
*
* Calling arguments: string str --> Linea
*
* Return value:      vector<std::string> resultados --> Subdivision de la cola
*
*********************************************************************/
std::vector<std::string> split(std::string str, std::string patron)
{
    int posInicio = 0;                  
    int posEncontrada = 0;
    std::string splitted;
    std::vector<std::string> resultados;

    while (posEncontrada >= 0)
    {
        posEncontrada = str.find(patron, posInicio);
        splitted = str.substr(posInicio, posEncontrada - posInicio);
        posInicio = posEncontrada + 1;
        resultados.push_back(splitted);
    }

    return resultados;
}