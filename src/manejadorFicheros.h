#ifndef MANEJADOR_FICHEROS_H
#define MANEJADOR_FICHEROS_H

#include <vector>
#include <string>

// Función para contar las líneas de un archivo
int ContarLineas(std::string nombre_Fichero);

// Función para leer un archivo y almacenar cada línea en un vector
std::vector<std::string> LeerFichero(std::string libro);

// Función para convertir una cadena a minúsculas
std::string toLower(std::string str);

// Función para dividir una línea de texto en palabras
std::vector<std::string> dividirFichero(std::string str, std::string espacio);

#endif /* MANEJADOR_FICHEROS_H */
