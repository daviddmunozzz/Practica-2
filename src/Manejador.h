#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

#ifndef MANEJADOR_H
#define MANEJADOR_H

int ContarLineas(std::string nombreFichero);
std::vector<std::string> LeerFichero(std::string libro);
std::vector<std::string> split(std::string str, std::string patron);
std::string toLower(std::string str);

#endif