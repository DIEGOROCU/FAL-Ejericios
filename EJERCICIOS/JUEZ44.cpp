// FP2-DG29 Diego Rodríguez Cubero

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

int busqueda(int ini, int fin){

    if (ini == fin){
        return ini;
    }
    else {
        int m = (ini + fin) / 2;
        cout << "? " << m << "\n";
        string aux;
        cin >> aux;
        if (aux == ">"){
            return busqueda(m + 1, fin);
        }
        else {
            return busqueda(ini, m);
        }

    }

}

bool resuelveCaso() {

    int min, max;

    std::cin >> min >> max;

    if (min == 0 && max == 0) {
        return false;
    }

    else {

        int res = busqueda(min, max);

        cout << "Respuesta: " << res << "\n";

        return true;

    }



}



int main() {

    // LLamada a la función para tratar cada caso
        while (resuelveCaso()){
        }

    return 0;

}