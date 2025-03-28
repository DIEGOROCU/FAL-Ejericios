// NOMBRE Y APELLIDOS:
// DNI: 

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//DESCRIPCION DEL ESPACIO DE SOLUCIONES


//MARCADORES UTILIZADOS


//PODA DE OPTIMALIDAD



//ALGORITMO DE VUELTA ATRÁS

bool esSolucion(vector<int> const& pMin, vector<int> const& ppC, int cantC){
    for (int i = 0; i < cantC; i++){
        if (ppC[i] < pMin[i]){
            return false;
        }
    }
    return true;
}

bool esValida(int policias, int policasMax){
    if (policasMax < policias){
        return false;
    }
    return true;
}


void asignarPatrullas(int const& cantCiudades, int const& cantPatrullas, int patrullasUsadas, int const& salarioReserva,
vector<int> const& policiasMinimos, vector<int> const& policiasMaximos, vector<int> const& salarios,
vector<int> const& policiasPorPatrulla,
vector<int> & policiasPorCiudad,
bool & sePuede, int & mejorDinero, int dineroActual){

    if (patrullasUsadas == cantPatrullas){
        if (esSolucion(policiasMinimos, policiasPorCiudad, cantCiudades)){
            if (!sePuede){
                sePuede = true;
                mejorDinero = dineroActual;
            }
            else {
                mejorDinero = min(mejorDinero, dineroActual);
            }
        }
    }
    else {
        for (int i = 0; i < cantCiudades; i++){
            if (esValida(policiasPorCiudad[i] + policiasPorPatrulla[patrullasUsadas], policiasMaximos[i])){
                policiasPorCiudad[i] += policiasPorPatrulla[patrullasUsadas];
                asignarPatrullas(cantCiudades, cantPatrullas, patrullasUsadas + 1, salarioReserva,
                policiasMinimos, policiasMaximos, salarios, policiasPorPatrulla, policiasPorCiudad,
                sePuede, mejorDinero, dineroActual + policiasPorPatrulla[patrullasUsadas]*salarios[i]);
                policiasPorCiudad[i] -= policiasPorPatrulla[patrullasUsadas];
            }
        }
        asignarPatrullas(cantCiudades, cantPatrullas, patrullasUsadas + 1, salarioReserva,
                policiasMinimos, policiasMaximos, salarios, policiasPorPatrulla, policiasPorCiudad,
                sePuede, mejorDinero, dineroActual + policiasPorPatrulla[patrullasUsadas]*salarioReserva);
    }

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
    int n, m, r; //ciudades, patrullas y sueldo de reserva
    cin >> n >> m >> r;
    vector<int> L(n), G(n), S(n); //minimo, maximo de personas admitidas en la ciudad y salarios por ciudad
    vector<int> P(m); //personas por patrulla
    
    for(int i=0; i<n; ++i)
        cin>> L[i];
    for(int i=0; i<n; ++i)
        cin>> G[i];
    for(int i=0; i<n; ++i)
        cin >> S[i];
    for(int i=0; i<m; ++i)
        cin >> P[i];

    int salarioMejor = 0; bool sepuede = false;
    vector<int> ppc(n, 0);

    asignarPatrullas(n, m, 0, r, L, G, S, P, ppc, sepuede, salarioMejor, 0);

    //LLamada inicial al algoritmo de vuelta atras
	
	if (sepuede)
		cout << salarioMejor << "\n";
	else
		cout << "NO\n";
	}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif
	

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto

	#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif
	
	return 0;
}