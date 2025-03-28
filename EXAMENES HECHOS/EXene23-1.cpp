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

cerosUnos(v, p, q) = (0 <= p <= q <= v.size()) && (p != v.size()) ((#a : p <= a < q && v[a] = 0) = (#b : p <= b < q && v[b] = 1))
Postcondicion iguales = #p,q : (q - p >= l) && (0 <= p <= q <= n) && (p != n)

I = 
mini <= i < n
dev = #p,q : (q - p >= l) && (0 <= p <= q <= i) && (p != i) && cerosUnos(v, p, q)
ceros = (#a: i - l <= a < i : v[a] = 0)

Cota: n - i

resuelve(v, tam, mini) = #p,q : (q - p >= l) && (0 <= p <= q <= tam) && (p != tam) && cerosUnos(v, p, q)

*/

int cerosUnos(vector<int> const& v, int tam, int mini){
    int ceros = 0, unos = 0;
    int dev = 1;
    for (int i = mini; i < tam; i++){
        ceros -= (ceros > 0) && (v[i - mini] == 0);
        ceros += (v[i] == 0);
        unos  -= (unos  > 0) && (v[i - mini] == 1);
        unos  += (v[i] == 1);
        dev += (ceros == unos);
    }
    return dev;
}

void resuelveCaso() {

    int tam, mini;
    cin >> mini >> tam;
    vector<int> v(tam);
    for (int i = 0; i < tam; i++){
        cin >> v[i];
    }
    cout << cerosUnos(v, tam, mini) << endl;

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