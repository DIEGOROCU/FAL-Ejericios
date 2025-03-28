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

int minimoRotados(vector<int> const& v, int ini, int fin) {
    // Caso base
    if (ini + 1 == fin) {
        return v[ini];
    }
    else {
        // Busqueda binaria
        int m = (ini + fin) / 2;
        if (min(v[ini], v[m - 1]) < min(v[m], v[fin - 1])) {
            return minimoRotados(v, ini, m);
        }
        else {
            return minimoRotados(v, m, fin);
        }
    }
}

bool resuelveCaso() {
    
    int tam;
    cin >> tam;
    
    if (!std::cin){
        return false;
    }
    else{

        vector<int> v(tam);
        for(int i = 0; i < tam; i++){
            cin >> v[i];
        }

        cout << minimoRotados(v, 0, tam) << endl;

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