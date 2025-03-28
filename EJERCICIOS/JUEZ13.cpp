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

// Funcion que nos dice si todos los elementos de un vector son pares entre dos posiciones p y q
bool todosPares(const vector<int> &v, int p, int q) {
    for (int i = p; i <= q; ++i) {
        if (v[i] % 2 != 0) {
            return false;
        }
    }
    return true;
}

// Funcion que nos dice si hay un segmento de tamaño k sin mas de k numeros pares
bool noMas(const vector<int> &v, int p, int q, int k) {
    for (int i = p; i + k <= q; ++i) {
        if (todosPares(v, i, i + k)) {
            return false;
        }
    }
    return true;
}

int maxSegmentoSinKPares(const vector<int> &v, int k) {
    // Variables auxiliares
    int i = 0;
    int max = 0, maxProv = 0, cont = 0;
    while (i < v.size()) {
        // Contamos los impares
        if (v[i] % 2 != 0) {
            maxProv++;
            ++i;
        }
        // Al encontrar un par
        else {
            // Avanzamos hasta encontrar un impar
            while (i < v.size() && v[i] % 2 == 0) {
                if (v[i] % 2 == 0) {
                    ++cont;
                }
                ++i;
            }
            // Si hemos encontrado mas de k pares
            if (cont > k) {
                // Actualizamos el maximo y reiniciamos las variables (podemos usar k pares)
                max = std::max(max, maxProv + k);
                maxProv = k;
                cont = 0;
            }
            // Si no hemos encontrado mas de k pares añadimos los pares al maximo provisional
            else {
                maxProv += cont;
                cont = 0;
            }
        }
    }
    // Devolvemos el maximo entre el maximo provisional y el maximo
    return std::max(max, maxProv);
}

void resuelveCaso() {

    // Leemos los datos de entrada
    int n, k;
    std::cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    // Devolvemos el resultado
    // Precondicion: n > 0
    // Invariante: {0 <= i <= n && cont = max(j : (Am: 0 <= j <= m <= i: v[m] % 2 == 0): i - j)}
    // Funcion de cota: n - i
    // Postcondicion: maxSegmentoSinKPares(v, k) = max(j : (Am->(j,n): noMas(v, m-j, m, k)): j)
    std::cout << maxSegmentoSinKPares(v, k) << '\n';

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