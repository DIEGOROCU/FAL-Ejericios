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
COSTE:
T(n) = T(n/2) + c
a = 1 ; b = 2 ; k = 0
T(n)->O(n^0logn)=O(logn)
*/

int seCruzan(vector<int> const& n, vector<int> const& g, int const& tam, int ini, int fin){

    if (ini == fin){
        return ini;
    }
    else {
        int m = (ini + fin) / 2;

        if (n[m] >= g[m]){
            return seCruzan(n, g, tam, ini, m);
        }
        else {
            return seCruzan(n, g, tam, m + 1, fin);
        }
    }


}

bool resuelveCaso() {
    
    //Leer caso de prueba: cin>>...
    int tam;
    cin >> tam;
    
    if (tam == 0){
        return false;
    }
    
    else{
        
        vector<int> nobita(tam);
        vector<int> gigante(tam);

        for (int i = 0; i < tam; i++){
            cin >> nobita[i];
        }
        for (int i = 0; i < tam; i++){
            cin >> gigante[i];
        }

        int c = seCruzan(nobita, gigante, tam, 0, tam - 1);

        if (nobita[c] == gigante[c]){
            cout << "HABLAN " << nobita[c] << "\n";
        }
        else {
            cout << "SE CRUZAN " << nobita[c - 1] << " " << nobita[c] << "\n";
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