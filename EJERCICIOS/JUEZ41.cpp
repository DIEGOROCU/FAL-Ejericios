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

void escogerParadas(int const& paradas, int const& maxParadas, int &mejorTiempo, int maxActual,
vector<int> const& distancias, int paradasEscogidas, int indi, bool & encontrado){

    if (paradasEscogidas == maxParadas){
        int tiempoActual = 0;
        while (indi < paradas){
            tiempoActual += distancias[indi];
            indi++;
        }
        maxActual = max(maxActual, tiempoActual);
        if (!encontrado){
            encontrado = true;
            mejorTiempo = maxActual;
        }
        else {
            mejorTiempo = min(mejorTiempo, maxActual);
        }
    }
    else {
        int tiempoActual = 0;
        for (int i = indi; i < paradas; i++){
            tiempoActual += distancias[i];
            int aux = maxActual;
            maxActual = max(maxActual, tiempoActual);
            escogerParadas(paradas, maxParadas, mejorTiempo, maxActual, distancias, paradasEscogidas + 1, i + 1, encontrado);
            maxActual = aux;
        }
    }

}

bool resuelveCaso() {
    
    int paradas, maxParadas;
    cin >> paradas >> maxParadas;
    
    if (paradas == 0 && maxParadas == 0){
        return false;
    }
    
    else{
        
        vector<int> distancias(paradas);
        for (int i = 0; i < paradas; i++){
            cin >> distancias[i];
        }

        int mejorTiempo;
        bool encontrado = false;
        escogerParadas(paradas, maxParadas, mejorTiempo, 0, distancias, 0, 0, encontrado);

        cout << mejorTiempo << endl;

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