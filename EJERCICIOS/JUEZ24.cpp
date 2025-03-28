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

int cantado(vector<int> const& v, int numCantado, int ini, int fin) {
    // Caso base
    if (ini + 1 == fin) {
        if (v[ini] - ini == numCantado) return v[ini];
        else return -1;
    }
    // Busqueda binaria
    else {
        int m = (ini + fin) / 2;
        if (v[m] - m == numCantado) return v[m];
        else if (v[m] - m < numCantado) return cantado(v, numCantado, m, fin);
        else return cantado(v, numCantado, ini, m);
    }
}

void resuelveCaso() {

    int tam, numCantado;
    cin >> tam >> numCantado;

    vector<int> v(tam);
    for (int i = 0; i < tam; i++) {
        cin >> v[i];
    }

    int res = cantado(v, numCantado, 0, tam);

    if (res == -1) cout << "NO" << endl;
    else cout << res << endl;

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