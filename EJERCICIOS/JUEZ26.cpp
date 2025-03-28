// Diego Rodriguez Cubero DG30 FAL

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

int tiempoOrdenar(vector<int> &v, int ini, int fin) {
    
    // Caso recursivo
    if (ini < fin) {
        
        // Dividimos el vector en dos partes
        int mitad = (ini + fin) / 2;
        
        // Llamamos recursivamente a la función para calcular el tiempo de ordenación en cada parte
        int izq = tiempoOrdenar(v, ini, mitad);
        int der = tiempoOrdenar(v, mitad + 1, fin);
        
        // Variables auxiliares
        int i = ini, j = mitad + 1, k = 0;
        vector<int> aux(fin - ini + 1);
        
        int tiempo = 0;
        
        // Mezclamos las dos partes
        while (i <= mitad && j <= fin) {
            
            if (v[i] <= v[j]) {
                aux[k] = v[i];
                i++;
            }
            else {
                aux[k] = v[j];
                j++;
                tiempo += mitad - i + 1;
            }
            k++;
        }
        
        // Copiamos los elementos restantes
        while (i <= mitad) {
            aux[k] = v[i];
            i++;
            k++;
        }
        while (j <= fin) {
            aux[k] = v[j];
            j++;
            k++;
        }
        
        // Copiamos del vector auxiliar al original
        for (int i = 0; i < fin - ini + 1; i++) {
            v[ini + i] = aux[i];
        }
        
        // Devolvemos el tiempo total
        return tiempo + izq + der;
    }
    // Caso base
    else {
        return 0;
    }
}

bool resuelveCaso() {
    
    // Leemos la cantidad de naves
    int tam;
    cin >> tam;
    
    if (!std::cin) {
        return false;
    }
    else {

        // Leemos las naves
        vector<int> v(tam);
        for (int i = 0; i < tam; i++) {
            cin >> v[i];
        }

        // Devolvemos el resultado
        cout << tiempoOrdenar(v, 0, tam - 1) << "\n";
        return true;
    }
}

int main() {
    
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());
    
    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}