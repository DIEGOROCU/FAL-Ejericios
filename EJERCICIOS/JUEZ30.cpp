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

bool esValido(vector<char> &v, int k) {
    return v[k] != 'v';
}

void construyeTorres(vector<char> &v, int k, int altura) {
    // Si ya tenemos la torre construida, la mostramos
    if (k == altura){
        for (int i = 0; i < altura; i++) {
            if (v[i] == 'r') {
                cout << "rojo ";
            }
            else if (v[i] == 'a') {
                cout << "azul ";
            }
            else if (v[i] == 'v') {
                cout << "verde ";
            }
        }
        cout << endl;
    }
    // Si no, seguimos construyendo
    else {
        v[k] = 'a';
        construyeTorres(v, k + 1, altura);
        v[k] = 'r';
        construyeTorres(v, k + 1, altura);
        // Solo añadimos la pieza verde si no hemos añadido una verde antes
        if (esValido(v, k - 1)) {
            v[k] = 'v';
            construyeTorres(v, k + 1, altura);
        }
    }


}

bool resuelveCaso() {
    
    int altura;
    cin >> altura;
    
    if (altura == 0) {
        return false;
    }
    
    else{
        
        // Añadimos la primera pieza roja
        vector<char> v(altura);
        v[0] = 'r';

        // Construimos las torres
        construyeTorres(v, 1, altura);
        cout << endl;

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