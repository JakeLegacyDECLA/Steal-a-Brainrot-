/*
Nombre: César Daniel Aguilar Kuri
Matricula: A01712823
Nombre del Proyecto: Steal a Brainrot!
Materia: Programación de estructuras de datos y algoritmos fundamentales
Profesor: Eduardo Daniel Juárez Pineda
*/


// LIBRERIAS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // find
#include <limits>    // numeric_limits
#include <utility> // para usar swap

// CLASES

#include "BubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"

using namespace std;

// MÉTODOS
void mostrarArreglos(const vector<string>& nombres,
                     const vector<string>& rarezas,
                     const vector<float>& costos) {
    cout << "Nombre, Rareza, Costo\n";
    for (size_t i = 0; i < nombres.size(); ++i) {
        cout << nombres[i] << ", " << rarezas[i] << ", " << costos[i] << "\n";
    }
}

// Captura un bloque de N personajes y los AGREGA (continúa desde el tamaño actual)
void capturarPersonajes(vector<string>& nombres,
                        vector<string>& rarezas,
                        vector<float>& costos,
                        const vector<string>& existentrarity)
{
    int cuantos = 0;
    cout << "¿Cuántos personajes ingresarás en este bloque? ";
    while (!(cin >> cuantos) || cuantos <= 0) {
        cout << "Valor inválido. Ingresa un entero > 0: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    // limpiar salto antes de usar getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int k = 0; k < cuantos; ++k) {
        string nombre, rareza;
        float  costo;

        size_t idx = nombres.size(); // índice real siguiente
        cout << "\nRegistro no. " << (idx + 1) << "\n";

        // nombre
        cout << "Nombre del personaje: ";
        getline(cin >> ws, nombre);
        while (nombre.empty()) {
            cout << "El nombre no puede estar vacío. Intenta de nuevo: ";
            getline(cin >> ws, nombre);
        }

        // rareza (validada)
        cout << "Rarezas válidas: Common, Rare, Epic, Legendary, BrainrotGod, Secret\n";
        cout << "Rareza: ";
        getline(cin >> ws, rareza);
        while (find(existentrarity.begin(), existentrarity.end(), rareza) == existentrarity.end()) {
            cout << "Rareza inválida. Debe ser una de: ";
            for (const auto& r : existentrarity) cout << r << " ";
            cout << "\nIntenta de nuevo: ";
            getline(cin >> ws, rareza);
        }

        // costo
        cout << "Costo (>= 0): ";
        while (!(cin >> costo) || costo < 0.0f) {
            cout << "Costo inválido. Debe ser >= 0. Intenta de nuevo: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        nombres.push_back(nombre);
        rarezas.push_back(rareza);
        costos.push_back(costo);
    }
    cout << "\nCaptura completa. Total acumulado: " << nombres.size() << "\n";
}

// MAIN 
int main() {
    // Arreglos PERSISTENTES para toda la sesión
    vector<string> nombres;
    vector<string> rarezas;
    vector<float>  costos;
    vector<string> existentrarity = {
        "Common","Rare","Epic","Legendary","BrainrotGod","Secret"
    };

    while (true) {
        // Menú
        cout << "\nBienvenido a Steal a Brainrot!\n";
        cout << "Selecciona la opción que quieres ejecutar:\n";
        cout << "1. Ingresar personajes, rarezas y costos a arreglos\n";
        cout << "2. Consultar arreglos\n";
        cout << "3. Realizar Bubble Sort (Ordena por Costo)\n";
        cout << "4. Realizar Insertion Sort (Ordena por Nombre)\n";
        cout << "5. Realizar Merge Sort (Ordena por Rareza)\n";
        cout << "6. Salir\n";
        cout << "> ";

        int op;
        if (!(cin >> op)) {
            // entrada no numérica
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida.\n";
            continue;
        }

        // Rango válido
        if (op < 1 || op > 6) {
            cout << "Opción no válida. Intenta (1-6).\n";
            continue;
        }

        // Acciones
        if (op == 1) {
            capturarPersonajes(nombres, rarezas, costos, existentrarity);
            // Al finalizar, REGRESA AUTOMÁTICAMENTE AL MENÚ y conserva los datos

        } else if (op == 2) {
            cout << "\nConsulta de Arreglos:\n";
            mostrarArreglos(nombres, rarezas, costos);

        } else if (op == 3) {
            cout << "[Bubble Sort] (Ordena por Costo)\n";
            cout << "Arreglos actuales: \n";
            mostrarArreglos(nombres, rarezas, costos);
            cout << "==================================\n";
            cout << "Arreglos con Bubble Sort (costo): \n";
            bubbleSortPorCosto(nombres, rarezas, costos);
            mostrarArreglos(nombres, rarezas, costos);

        } else if (op == 4) {
            cout << "[Insertion Sort] pendiente (Ordena por Nombre)\n"; //PENDIENTE

        } else if (op == 5) {
            cout << "[Merge Sort] pendiente (Ordena por Rareza)\n"; //PENDIENTE

        } else if (op == 6) {
            cout << "Saliendo. ¡Éxito!\n"; 
        }
    }

    return 0;
}
