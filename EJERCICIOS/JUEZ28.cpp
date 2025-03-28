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

// Estructura para guardar los datos de los jugadores
struct tJugador {
    string nombre;
    int canicas;
};

tJugador ganador(vector<tJugador> const& jugadores) {
    
    // Caso base
    if (jugadores.size() == 1) {
        return jugadores[0];
    }
    else {
        
        // Llamadas recursivas
        tJugador izquierda = ganador(vector<tJugador>(jugadores.begin(), jugadores.begin() + jugadores.size() / 2));
        tJugador derecha = ganador(vector<tJugador>(jugadores.begin() + jugadores.size() / 2, jugadores.end()));

        // Comprobamos quien tiene mas canicas y devolvemos el ganador con la mitad de las canicas del perdedor
        if (izquierda.canicas >= derecha.canicas) {
            izquierda.canicas += derecha.canicas / 2;
            return izquierda;
        }
        else {
            derecha.canicas += izquierda.canicas / 2;
            return derecha;
        }

    }
}

bool resuelveCaso() {
    
    // Lectura de datos
    int tam;
    cin >> tam;
    
    if (!std::cin){
        return false;
    }
    else {
        
        // Lectura de los jugadores
        vector<tJugador> jugadores(tam);
        for (int i = 0; i < tam; i++) {
            cin >> jugadores[i].nombre;
            cin >> jugadores[i].canicas;
        }

        // Calculamos el ganador
        tJugador gan = ganador(jugadores);

        // Mostramos el ganador
        cout << gan.nombre << " " << gan.canicas << "\n";

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