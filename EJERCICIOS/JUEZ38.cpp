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

int segmentosIguales(vector<int> const& v, int mini) {
    // Variable a devolver
    // cont = max(k: todosIguales(v, i - k + 1, i): k)
    int dev = 0, cont = 1;

    // Ajustamos el resultado si la longitud minima es 1, ya que todos los segmentos de longitud 1 son validos
    if (mini == 1) {
        dev++;
    }
    
    for (int i = 1; i < v.size(); i++) {
        // Si el actual es igual al anterior, incrementamos el contador de todosIguales(v, i - k + 1, i)
        if (v[i] == v[i - 1]) {
            cont++;
        }
        // Si no, reseteamos el contador
        else {
            cont = 1;
        }
        // Si el contador es mayor o igual que el minimo, incrementamos el resultado
        if (cont >= mini) {
            dev += cont - mini + 1;
        }
    }
    // Devolvemos el resultado
    return dev;
}

void resuelveCaso() {

    // Leemos la entrada
    int mini, tam;
    cin >> mini >> tam;

    // Leemos el vector
    vector<int> v(tam);
    for (int i = 0; i < tam; i++) {
        cin >> v[i];
    }

    // Precondicion: tam >= mini >= 1
    // Invariante: 0 <= i < tam && cont = max(k: todosIguales(v, i - k + 1, i): k)
    // Funcion de cota: tam - i
    // Postcondicion: segmentosIguales(v, mini) = #k,l: (0 <= k <= l < tam && l - k >= mini && todosIguales(v, k, l))
    cout << segmentosIguales(v, mini) << endl;

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