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

bool esValido(vector<char> &v, int k, int numAzules, int numVerdes) {
    return v[k] != 'v' && numAzules >= numVerdes;
}

bool construyeTorres(vector<char> &v, int k, int altura, bool&hayTorres, int rojas, int azules, int verdes, int rojasUsadas, int azulesUsadas, int verdesUsadas) {
    // Revisamos que la torre pueda ser construida
    if (azulesUsadas + verdesUsadas > altura / 2) return false;
    // Si ya tenemos la torre construida, la mostramos
    if (k == altura && rojasUsadas > azulesUsadas + verdesUsadas) {
        hayTorres = true;
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
    else if (k < altura) {
        // Revisamos si podemos añadir una pieza de cada color
        if (azulesUsadas < azules) {
            v[k] = 'a';
            construyeTorres(v, k + 1, altura, hayTorres, rojas, azules, verdes, rojasUsadas, azulesUsadas + 1, verdesUsadas);
        }
        if (rojasUsadas < rojas) {
            v[k] = 'r';
            construyeTorres(v, k + 1, altura, hayTorres, rojas, azules, verdes, rojasUsadas + 1, azulesUsadas, verdesUsadas);
        }
        if (verdesUsadas < verdes && esValido(v, k - 1, azulesUsadas, verdesUsadas + 1)) {
            v[k] = 'v';
            construyeTorres(v, k + 1, altura, hayTorres, rojas, azules, verdes, rojasUsadas, azulesUsadas, verdesUsadas + 1);
        }
    }

    // Devolvemos si hay torres construidas
    return hayTorres;
}

bool resuelveCaso() {
    
    int altura, ro, az, ve;
    cin >> altura >> az >> ro >> ve;
    
    if (altura == 0) {
        return false;
    }
    
    else{
        
        // Añadimos la primera pieza roja
        vector<char> v(altura);
        v[0] = 'r';

        // Construimos las torres
        bool hayTorres = false;
        if (!construyeTorres(v, 1, altura, hayTorres, ro, az, ve, 1, 0, 0)) {
            cout << "SIN SOLUCION" << endl;
        }
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