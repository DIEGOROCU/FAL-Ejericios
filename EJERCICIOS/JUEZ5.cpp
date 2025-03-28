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

bool bienDividido(vector<int> const& v, int pos) {
    // Buscamo la temperatura más alta hasta la posición pos (incluida)
    int max = v[0];
    for (int i = 1; i <= pos; ++i) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    // Buscamos la temperatura más baja desde la posición pos+1 hasta el final
    if (pos == v.size() - 1) {
        return true;
    }
    int min = v[pos + 1];
    for (int j = pos + 2; j < v.size(); ++j) {
        if (v[j] < min) {
            min = v[j];
        }
    }

    // Comprobamos si está bien dividido
    return max < min;
}

void resuelveCaso() {

    // Precondicion: {tam > 0 && 0 <= pos < tam}
    // Leemos los datos de entrada
    int tam, pos;
    std::cin >> tam >> pos;
    vector<int> temperaturas(tam);
    for (int i = 0; i < tam; ++i) {
        std::cin >> temperaturas[i];
    }

    // Invariante: {0 <= i <= pos && pos < j < tam}
    // Función de cota: {min(pos, tam - pos - 2) - i}
    // Comprobamos si está bien dividido
    bool dividido = bienDividido(temperaturas, pos);

    // Postcondicion {Ai,j: 0 <= i <= pos && pos < j < tam : temperaturas[i] < temperaturas[j]}
    // Mostramos el resultado
    if (dividido) {
        std::cout << "SI\n";
    }
    else {
        std::cout << "NO\n";
    }

}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    
    
    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }
    
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}