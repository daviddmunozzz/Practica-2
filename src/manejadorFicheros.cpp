/**********************************************************************
* Class Name: manejadorFicheros.cpp
* Author/s name: Daniel Aguado y Daviz Muñoz.
* Release/Creation date: 28-3-2024
* Class version: 1-0
* Class description: Lógica para leer y dividir el fichero
*
***********************************************************************/
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**********************************************************************
* Method name: ContarLineas
*
* Description of the Method: Cuenta las lineas del fichero para poder
*                            hacer su division
*
* Calling arguments:         string nombre_fichero --> Nombre del fichero
*                                                  
*
* Return value:              int contador_lineas --> Nº lineas del fichero
*
* Required Files: Se requiere que el fichero a leer esté en la ruta --> ..\library\<nombre_fichero>.txt
*
*********************************************************************/
int ContarLineas(string nombre_Fichero)
{
    ifstream fichero(nombre_Fichero);   //Objeto tipo ifstream para leer el fichero
    int contador_lineas = 0;            //Contamos las lineas que tiene el fichero
    string linea_leida;                 //Linea leida

    while (getline(fichero, linea_leida))  //Recorro el fichero hasta que encuentre una linea vacia
    {
        contador_lineas++;                 //Obtengo las lineas del fichero
    }
    return contador_lineas;                //Devuelvo las lineas del fichero
}

/**********************************************************************
* Method name: LeerFichero
*
* Description of the Method: Lee el fichero y almacena cada una de las
                             lineas en una posicion del vector
*
* Calling arguments:         string nombre_fichero --> Nombre del fichero
*                                                  
*
* Return value:              vector<string> lineas_del_fichero
*
* Required Files: Se requiere que el fichero a leer esté en la ruta --> ..\library\<nombre_fichero>.txt
*
*********************************************************************/
vector<string> LeerFichero(string libro)
{
    ifstream fichero(libro);                           //Objeto tipo ifstream para leer el fichero
    vector<string> lineas_del_fichero;              //Vector de lineas para almacenar cada una de las que tenga el fichero
    string linea_leida;                             //Linea leida

    while (getline(fichero, linea_leida))
    {
        lineas_del_fichero.push_back(linea_leida);  //Mientras haya linea, las voy encolando en el vector
    }

    return lineas_del_fichero;                      //Devuelvo el vector de lineas del fichero           
}

/**********************************************************************
* Method name: toLower
*
* Description of the Method: Metodo para poner el fichero en minusculas
*                            por si dieran problemas las mayusculas
*
*
*********************************************************************/
string toLower(string str)
{
    string strLower = str;
    transform(strLower.begin(), strLower.end(), strLower.begin(), [](unsigned char c){
        return tolower(c);
    });
    return strLower;
}

/**********************************************************************
* Method name: dividirFichero
*
* Description of the Method: Divido la linea del texto en palabras
*
* Calling arguments:         string str --> Nombre del fichero
*                            string espacio --> token por el cual cortamos la linea                      
*
* Return value:              Vector de palabras que se encuentran en la linea
*
* Required Files: Se requiere que el fichero a leer esté en la ruta --> ..\library\<nombre_fichero>.txt
*
*********************************************************************/
vector<string> dividirFichero(string str, string espacio)
{  
    int posicion_inicio = 0;        //posicion desde la que empiezo
    int posicion_encontrada = 0;    //Posicion siguiente
    string palabra_actual;          //Palabra actual que se va a guardar en el vector
    vector<string> resultados;      //Vector que almacena las diferentes palabras
    
    while(posicion_encontrada >= 0)
    {
        posicion_encontrada = str.find(espacio, posicion_inicio);                           //Busco el siguiente espacio
        palabra_actual = str.substr(posicion_inicio, posicion_encontrada - posicion_inicio);//Tomo la siguiente palabra
        posicion_inicio = posicion_encontrada + 1;                                          //Avanzo a la siguiente palabra despues del espacio
        resultados.push_back(palabra_actual);                                               //Guardo la palabra en el vector
    }
    return resultados;                                                                      //Devuelvo el vector de palabras
}