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


*/

bool esMinimalista(vector<int> const& v, int & mini, int const& ini, int const& fin, int & pos){
    bool repetido = false;
    mini = v[ini];
    int i = ini + 1;

    while (i <= fin){
        if (v[i] == mini){
            repetido = true;
        }
        else if (v[i] < mini){
            mini = v[i];
            repetido = false;
            pos = i;
        }
        i++;
    }
    return !repetido;

}

bool esHiper(vector<int> const& v, int ini, int fin){

    if (ini >= fin) return true;
    int mini = v[ini], pos = 0;
    return esMinimalista(v, mini, ini, fin, pos) && esHiper(v, ini, pos - 1) && esHiper(v, pos + 1, fin);

}

/*
T(n) = T(n - 1) + n -> n^2
T(n) = 2T(n/2) + n -> nlogn
*/

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

        if (esHiper(v, 0, tam - 1)){
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