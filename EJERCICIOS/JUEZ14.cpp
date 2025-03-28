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

// Función que determina si todos los elementos de un segmento de un vector son pares
bool todosPares(const vector<int> &v, int p, int q) {
    for (int i = p; i < q; ++i) {
        if (v[i] % 2 != 0) {
            return false;
        }
    }
    return true;
}

// Función que cuenta cuántos segmentos de un vector son pares
int segmentosPares(const vector<int> &v, int p, int q) {
    // Iniciamos las variables
    int cont = 0;
    int i = 0;
    int segProv = 1;
    // Recorremos el vector
    while (i < q) {
        // Si el número es par, calculamos la longitud del segmento de pares
        if (v[i] % 2 == 0) {
            segProv = 1;
            while (i + segProv < q && v[i + segProv] % 2 == 0) {
                ++segProv;
            }
            // Añadimos el número de segmentos que hemos encontrado (incluyendo los subsegmentos)
            cont += segProv * (segProv + 1) / 2;
            i += segProv;
            segProv = 0;
        } else {
            // Si no es par, pasamos al siguiente número
            ++i;
        }
    }
    // Devolvemos el resultado
    return cont;
}


void resuelveCaso() {

    // Leemos los datos
    int numNum;
    cin >> numNum;
    vector<int> v(numNum);
    for (int i = 0; i < numNum; ++i) {
        cin >> v[i];
    }

    // Calculamos el resultado y lo devolvemos
    // Precondición: numNum >= 0
    // Invariante: cont = (#[k,l] : 0 <= k <= l < numNum && l - k <= longitud : todosPares(v, k, l))
    // Función de cota: numNum - i - segProv
    // Postcondición: cont = (#[k,l] : 0 <= k <= l < numNum: todosPares(v, k, l))
    cout << segmentosPares(v, 0, numNum) << '\n';

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