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

bool parcialmenteOrdenado(vector<int> const& v) {
    
    // Caso base, si el vector tiene 1 elemento esta parcialmente ordenado
    if (v.size() <= 1) return true;

    // Comprobamos los maximos y minimos de cada mitad
    int maxIz = v[0], minIz = v[0], maxDe = v[v.size()-1], minDe = v[v.size()-1];
    for (int i = 0; i < v.size()/2; ++i) {
        if (v[i] > maxIz) maxIz = v[i];
        if (v[i] < minIz) minIz = v[i];
    }
    for (int i = v.size()/2; i < v.size(); ++i) {
        if (v[i] > maxDe) maxDe = v[i];
        if (v[i] < minDe) minDe = v[i];
    }

    // Comprobamos si esta parcialmente ordenado
    bool esParcialMenteOrdenado = (maxIz <= maxDe) && (minIz <= minDe);

    vector <int> v1(v.begin(), v.begin() + v.size()/2);
    vector <int> v2(v.begin() + v.size()/2, v.end());

    // Si es parcialmente ordenado, comprobamos si las dos mitades son parcialmente ordenadas recursivamente
    return esParcialMenteOrdenado && parcialmenteOrdenado(v1) && parcialmenteOrdenado(v2);
     
}

bool resuelveCaso() {
 
    // Leemos los datos de entrada
    int num;
    std::cin >> num;
    
    // Si el primer numero es 0, terminamos
    if (num <= 0){
        return false;
    }   
    else{

        // Leer el resto de numeros
        vector<int> v;
        while (num != 0) {
            v.push_back(num);
            std::cin >> num;
        }
        
        // Devolvemos si es parcialmente ordenado o no
        if (parcialmenteOrdenado(v)) {
            std::cout << "SI\n";
        }
        else {
            std::cout << "NO\n";
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