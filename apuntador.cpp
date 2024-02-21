#include <iostream>
using namespace std;
#include <string>

// Clase Corredor que almacena la información de cada corredor
class Corredor {
public:
    std::string nombre;
    int edad;
    char sexo;

    Corredor(std::string nombre, int edad, char sexo) {
        this->nombre = nombre;
        this->edad = edad;
        this->sexo = sexo;
    }
};

void clasificarYMostrar(Corredor** corredores, int size) {
    std::cout << "\nCATEGORIAS:\n";

    for (int i = 0; i < size; i++) {
        Corredor* corredor = corredores[i];
        if (corredor->edad < 18) {
            std::cout << corredor->nombre << " (Categoria Juvenil, Edad: " << corredor->edad << ", Sexo: " << corredor->sexo << ")\n";
        } else if (corredor->edad < 40) {
            std::cout << corredor->nombre << " (Categoria Adulta, Edad: " << corredor->edad << ", Sexo: " << corredor->sexo << ")\n";
        } else {
            std::cout << corredor->nombre << " (Categoria Veterana, Edad: " << corredor->edad << ", Sexo: " << corredor->sexo << ")\n";
        }
    }
}

int main() {
    const int size = 5;
    Corredor* corredores[size]; // Usando punteros para almacenar objetos de tipo Corredor

    for (int i = 0; i < size; i++) {
        std::string nombre;
        int edad;
        char sexo;

        std::cout << "Ingrese el nombre del corredor " << (i + 1) << ":\n";
        std::getline(std::cin, nombre);

        std::cout << "Ingrese la edad del corredor " << (i + 1) << ":\n";
        std::cin >> edad;
        std::cin.ignore(); // Limpiar el buffer de entrada

        std::cout << "Ingrese el sexo del corredor " << (i + 1) << " (M/F):\n";
        std::cin >> sexo;
        std::cin.ignore(); // Limpiar el buffer de entrada después de leer un char

        corredores[i] = new Corredor(nombre, edad, sexo); // Creando objetos Corredor en el heap
    }

    clasificarYMostrar(corredores, size);

    // Liberar la memoria asignada con new
    for (int i = 0; i < size; i++) {
        delete corredores[i];
    }

    return 0;
}
