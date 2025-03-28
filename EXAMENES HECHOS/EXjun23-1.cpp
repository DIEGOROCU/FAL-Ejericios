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
PRE: forall i : 0 <= i < n : v[i] >= 0;
n > 0;
POS: 
esMinimalista(v, ini, fin) = forall k : 0 <= k < n : (exists m : 0 <= m <= k : (forall a : 0 <= a <= k && a != m : v[a]>v[m]));
INV:
I = {
0 <= i < n
min = min k : 0 <= k < i : v[k];
minimalista = esMinimalista(v, 0, i)
}

COTA: n - i

COSTE: n

*/

bool esMinimalista(vector<int> const& v){
    bool minimalista = true;
    int min = v[0];
    int i = 1;

    while (i < v.size()){
        if (v[i] == min){
            minimalista = false;
        }
        else if (v[i] < min){
            min = v[i];
        }
        i++;
    }

    return minimalista;

}

bool resuelveCaso() {
    
    int tam;
    cin >> tam;   

    if (tam == -1){
        return false;
    }
    
    else{
        //Resolver problema
        //Escribir resultado

        vector<int> v(tam);
        for (int i = 0; i < tam; i++){
            cin >> v[i];
        }

        if (esMinimalista(v)){
            cout << "SI" << endl;
        }
        else {
            cout << "NO" << endl;
        }

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