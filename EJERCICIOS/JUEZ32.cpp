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

// Funcion que revisa si una pieza puede ser colocada en la fila y columna dada
bool esValida(vector<int> &casillasRotas, vector <bool> &filasUsadas, vector <int> &diagonal1Usadas, vector <int> &diagonal2Usadas, int fila, int columna, bool esTorre, int tamTablero){
    
    //Revisamos si la casilla es valida
    if (casillasRotas[fila] == columna || filasUsadas[fila] || diagonal1Usadas[fila + columna] > esTorre || diagonal2Usadas[fila - columna + tamTablero - 1] > esTorre){
        return false;
    }
    return true;
}

void colocarPiezas(vector<int> &casillasRotas, int&posibilidades, int torres, int reinas, int torresUsadas, int reinasUsadas, vector <bool> &filasUsadas, vector <int> &diagonal1Usadas, vector <int> &diagonal2Usadas){
    
    // Si ya hemos colocado todas las piezas, incrementamos el contador de posibilidades
   if (torresUsadas == torres && reinasUsadas == reinas){
        posibilidades++;
    }
   else {
    
        // Si no, intentamos colocar la siguiente pieza (torre y/o reina) en cada fila de la siguiente columna, revisando si es válida
        for (int i = 0; i < torres + reinas; i++){
            if (reinasUsadas < reinas && esValida(casillasRotas, filasUsadas, diagonal1Usadas, diagonal2Usadas, i, torres + reinas, false, torres + reinas)){
                filasUsadas[i] = true;
                diagonal1Usadas[i + torresUsadas + reinasUsadas] = 2;
                diagonal2Usadas[i - (torresUsadas + reinasUsadas) + torres + reinas - 1] = 2;
                colocarPiezas(casillasRotas, posibilidades, torres, reinas, torresUsadas, reinasUsadas + 1, filasUsadas, diagonal1Usadas, diagonal2Usadas);
                filasUsadas[i] = false;
                diagonal1Usadas[i + torresUsadas + reinasUsadas] = 0;
                diagonal2Usadas[i - (torresUsadas + reinasUsadas) + torres + reinas - 1] = 0;
              
            }
            if (torresUsadas < torres && esValida(casillasRotas, filasUsadas, diagonal1Usadas, diagonal2Usadas, i, torres + reinas, true, torres + reinas)){
                filasUsadas[i] = true;
                diagonal1Usadas[i + torresUsadas + reinasUsadas] = 1;
                diagonal2Usadas[i - (torresUsadas + reinasUsadas) + torres + reinas - 1] = 1;
                colocarPiezas(casillasRotas, posibilidades, torres, reinas, torresUsadas + 1, reinasUsadas, filasUsadas, diagonal1Usadas, diagonal2Usadas);
                filasUsadas[i] = false;
                diagonal1Usadas[i + torresUsadas + reinasUsadas] = 0;
                diagonal2Usadas[i - (torresUsadas + reinasUsadas) + torres + reinas - 1] = 0;
            }
        }

    }

}

bool resuelveCaso() {
    
    // Leemos los datos de entrada
    int torres, reinas, numCasillasRotas;
    std::cin >> torres >> reinas >> numCasillasRotas;
    
    if (!std::cin){
        return false;
    }
    
    else{
        
        // Leemos el resto de datos
        vector<int> casillasRotas(torres + reinas);
        vector<int> tablero(torres + reinas, -1);
        for (int i = 0; i < torres + reinas; i++){
            casillasRotas[i] = -1;
        }
        for (int i = 0; i < numCasillasRotas; i++){
            int x;
            cin >> x;
            cin >> casillasRotas[x];
        }
        vector <bool> filasUsadas(torres + reinas, false);
        vector <int> diagonal1Usadas(2 * (torres + reinas), 0);
        vector <int> diagonal2Usadas(2 * (torres + reinas), 0);

        // Solucionamos el problema
        int posibilidades = 0;
       colocarPiezas(casillasRotas, posibilidades, torres, reinas, 0, 0, filasUsadas, diagonal1Usadas, diagonal2Usadas);

        cout << posibilidades << endl;

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