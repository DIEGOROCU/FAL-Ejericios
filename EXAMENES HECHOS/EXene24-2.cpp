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

/*
T(n) = T(n/2) + c
a = 1 ; b = 2 ; k = 0
a = b^k -> O(logn)
*/

int maxi(vector<int> const& v, int ini, int fin){
    if (ini + 1 == fin){
        return v[fin] - v[ini];
    }
    else {
        int m = (fin + ini) / 2;
        if (v[m] - v[m - 1] < v[m + 1] - v[m]){
            return maxi(v, m, fin);
        }
        else {
            return maxi(v, ini, m);
        }
    }
}

void resuelveCaso() {

    int tam;
    cin >> tam;
    vector<int> v(tam);
    for (int i = 0; i < tam; i++){
        cin >> v[i];
    }

    cout << maxi(v, 0, tam - 1) << endl;

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