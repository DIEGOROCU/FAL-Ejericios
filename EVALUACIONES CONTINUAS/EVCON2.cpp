// NOMBRE Y APELLIDOS 
// 

// Comentario general sobre la solucion,
// explicando como se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


//Implementa la funcion recursiva
bool esExtrano(vector<int> const&v, int ini, int fin, int & sumPar, int & prodPar, int & sumImp, int & prodImp){
    if (ini == fin){

        int aux = v[ini];

        if (aux % 2 == 0){
            sumPar += aux;
            prodPar *= aux;
        }
        else {
            sumImp += aux;
            prodImp *= aux;
        }

        return true;

    }
    else {

        int m = (fin - ini) / 2;
        m += ini;

        bool Iz = esExtrano(v, ini, m, sumPar, prodPar, sumImp, prodImp);

        int sumParIz = sumPar;
        int sumImpIz = sumImp;
        int prodParIz = prodPar;
        int prodImpIz = prodImp;

        sumPar = 0;
        sumImp = 0;
        prodPar = 1;
        prodImp = 1;

        bool Dr = esExtrano(v, m + 1, fin, sumPar, prodPar, sumImp, prodImp);

        int sumParDr = sumPar;
        int sumImpDr = sumImp;
        int prodParDr = prodPar;
        int prodImpDr = prodImp;

        sumPar = sumParDr + sumParIz;
        sumImp = sumImpDr + sumImpIz;
        prodPar = prodParDr * prodParIz;
        prodImp = prodImpDr * prodImpIz;

        return (Iz || Dr) && ((sumParIz + prodImpIz) <= (sumImpDr + prodParDr));

    }
}

//Analisis justificado del coste de esta funcion recursiva 
/*
Cada llamada a la funcion recursiva hace otras 2 llamadas, cada una con la mitad de datos (excepto en el caso base que hace operaciones de coste lineal o(1))
Ademas de varias operaciones de coste lineal o(1)
Asi: T(n) = 2*T(n/2) + k
Por tanto: esExtrano->o(n^log2(2))=o(n)
*/


bool resolver(vector<int> const& v)
//Esta funcion determina si v es extraño
{
	//Invoca aqui a tu funcion recursiva
    int sumPar = 0;
    int sumImp = 0;
    int prodPar = 1;
    int prodImp = 1;

    return esExtrano(v, 0, v.size() - 1, sumPar, prodPar, sumImp, prodImp);
}


void resuelveCaso() {
	int n = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
			cin >> v[i];
	if (resolver(v))
		cout << "SI\n";
	else
		cout << "NO\n";
}

int main() {
	// Para la entrada por fichero
#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE 
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
