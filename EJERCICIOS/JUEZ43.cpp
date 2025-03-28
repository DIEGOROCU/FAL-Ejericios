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

bool esValida(vector<vector<float>> const& distancias, vector<vector<bool>> const& allegados,
vector<bool> & mesasUsadas, int persona, int mesa, int & cantAllegadosPersona,
vector<int> const& mesaPorPersona){
    if (mesasUsadas[mesa]){
        return false;
    }
    for (int i = 0; i < persona; i++){
            if (distancias[mesaPorPersona[i]][mesaPorPersona[persona]] < 2){
                if (!allegados[i][persona]){
                    return false;
                }
                else {
                cantAllegadosPersona++;
                }
            } 
        }
    return true;
}

void sentar(vector<vector<float>> const& distancias, vector<vector<bool>> const& allegados,
int const& plazas, int const& personas,
int cantParejasAllegadas, int & maxAllegadas, int personasSentadas, vector<bool> & mesasUsadas,
bool & sePuede, vector<int> & mesaPorPersona){

    if (personasSentadas == personas){
        sePuede = true;
        maxAllegadas = max(maxAllegadas, cantParejasAllegadas);
    }
    else {
        for (int i = 0; i < plazas; i++){
            int cantAllegadosPersona = 0;
            mesaPorPersona[personasSentadas] = i;
            if (esValida(distancias, allegados, mesasUsadas, personasSentadas, i, cantAllegadosPersona, mesaPorPersona)){
                mesasUsadas[i] = true;
                sentar(distancias, allegados, plazas, personas, cantParejasAllegadas + cantAllegadosPersona,
                maxAllegadas, personasSentadas + 1, mesasUsadas, sePuede, mesaPorPersona);
                mesasUsadas[i] = false;
            }
            mesaPorPersona[personasSentadas] = -1;
        }
    }

}

void resuelveCaso() {

    int plazas, personas;
    cin >> plazas >> personas;

    vector<vector<float>> distancias (plazas, vector<float> (plazas));
    vector<vector<bool>> allegados (personas, vector<bool> (personas, false));

    for (int i = 0; i < plazas; i++){
        for (int j = 0; j < plazas; j++){
            cin >> distancias[i][j];
        }
    }

    for (int i = 0; i < personas; i++){
        for (int j = 0; j < personas; j++){
            int aux;
            cin >> aux;
            if (aux == 1){
                allegados[i][j] = true;
            }
            else {
                allegados[i][j] = false;
            }
        }
    }

    int maxAllegados = 0;
    bool sePuede = false;
    vector<bool> mesasUsadas(plazas, false);
    vector<int> mesaPorPersona(personas, -1);

    sentar(distancias, allegados, plazas, personas, 0, maxAllegados, 0, mesasUsadas, sePuede, mesaPorPersona);

    if (sePuede){
        cout << "PAREJAS " << maxAllegados << "\n";
    }
    else{
        cout << "CANCELA" << "\n";
    }

}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    
    
    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }
    
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}