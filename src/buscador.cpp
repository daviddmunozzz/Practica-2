#include "definitions.h"


int main(int argc, char *argv[])
{
    if(argc < 4)
    {
        std::cout << "Error: Faltan argumentos. SSOOIIGLE <nombre_fichero> <palabra> <numero_hilos>" << std::endl;
        exit(EXIT_FAILURE);
    }   
}

/* void menu()  // En caso de no pasar por argumentos
{
    std::vector<std::string> titulos;

     for (const auto& entry : std::filesystem::directory_iterator(LIBRERIA)) {
        if (entry.is_regular_file()) {
            titulos.push_back(entry.path().filename().string());
        }
    }

    std::cout << "Seleccione un título:" << std::endl;
    for (size_t i = 0; i < titulos.size(); ++i) {
        std::cout << i + 1 << ". " << titulos[i].substr(0, titulos[i].size() - 4) << std::endl;
    }

    std::cout << "Ingrese el número correspondiente al libro que desea seleccionar: ";
    int opcion;
    std::cin >> opcion;

} */