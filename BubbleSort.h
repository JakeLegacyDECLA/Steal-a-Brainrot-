/*
Nombre: César Daniel Aguilar Kuri
Matricula: A01712823
Nombre del Proyecto: Steal a Brainrot!
Materia: Programación de estructuras de datos y algoritmos fundamentales
Profesor: Eduardo Daniel Juárez Pineda
*/

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <vector>
#include <string>
#include <unordered_map>
#include <utility> //swap

using namespace std;

// ===== Jerarquía global de rarezas =====
// Common (menos importante) -> Secret (más importante)
inline int rarityRank(const string& r) {
    static const unordered_map<string,int> RANK = { // O(1)
        {"Common", 1},
        {"Rare", 2},
        {"Epic", 3},
        {"Legendary", 4},
        {"BrainrotGod", 5},
        {"Secret", 6}
    };
    auto it = RANK.find(r);
    return (it == RANK.end()) ? 0 : it->second; // 0 si no se reconoce (queda al inicio)
}

inline void swapFila(
    size_t i, size_t j,
    vector<string>& nombres,
    vector<string>& rarezas,
    vector<float>& costos) {

    swap(nombres[i], nombres[j]); // O(1)
    swap(rarezas[i], rarezas[j]); // O(1)
    swap(costos[i], costos[j]); // O(1)

    }

inline void bubbleSortPorCosto(
    vector<string>& nombres,
    vector<string>& rarezas,
    vector<float>& costos) {

        size_t n = nombres.size(); // O(1)
        if (rarezas.size() != n || costos.size() != n || n < 2) return; // O(1) 
        //si los vectores no miden lo mismo o hay menos de 2 elementos, no hay nada que ordenar

        bool huboSwap; 
        for (size_t fin = n; fin > 1; --fin) { // O(n) (peor/promedio caso) //cada pasada deja el mayor en fin-1
            huboSwap = false; 
            for (size_t i = 0; i + 1 < fin; ++i) { // O(n^2) (peor/promedio caso)
                //compara [0... fin-1] usando i e i+1
                if ((costos[i] > costos[i+1]) || // O(1) comparan 2 floats
                    (costos[i] == costos[i+1] && // O(1)
                    nombres[i] > nombres[i+1])) { // O(1) siempre es O(1)

                        swapFila(i, i+1, nombres, rarezas, costos); // O(1)
                        huboSwap = true; // O(1)
                    }
        }
        if(!huboSwap) break; // O(1)
    }
}

#endif
