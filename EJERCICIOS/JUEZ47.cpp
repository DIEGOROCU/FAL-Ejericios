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

int empieza(vector<int> const& notas, int const& paginas, int const& seguidas){
    int dev = 0;
    int maxi = notas[0];
    int sumanotasAct = 0, sumanotasMax = 0;
    int restantes = seguidas;
    for (int i = 0; i < seguidas; i++){
        sumanotasAct += notas[i];
        if (notas[i] > maxi){
            maxi = notas[i];
            restantes = seguidas;
            dev = i - seguidas + 1;
        }
        else if (notas[i] == maxi){
            restantes = seguidas;
        }
        restantes--;
    }
    sumanotasMax = sumanotasAct;
    for (int i = seguidas; i < paginas; i++){
        if (notas[i] > maxi){
            maxi = notas[i];
            restantes = seguidas;
            dev = i - seguidas + 1;
        }
        else if (notas[i] == maxi){
            restantes = seguidas;
        }
        sumanotasAct += notas[i] - notas[i - seguidas];
        if (restantes > 0){
            if (sumanotasAct >= sumanotasMax){
                sumanotasMax = sumanotasAct;
                dev = i - seguidas + 1;
            }
            restantes--;
        }
    }
    if (restantes > 0){
        if (sumanotasAct >= sumanotasMax){
                sumanotasMax = sumanotasAct;
                dev = paginas - seguidas;
        }
    }
    return dev;
}

bool resuelveCaso() {
    
    int paginas, seguidas;
    cin >> paginas >> seguidas;
    
    if (paginas == 0 && seguidas == 0){
        return false;
    }
    
    else{
        vector<int> notas(paginas);
        for (int i = 0; i < paginas; i++){
            cin >> notas[i];
        }
        cout << empieza(notas, paginas, seguidas) << endl;
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