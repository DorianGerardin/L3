#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

void grapheRandom(int n, int m, int edge[][2]) {

	srand(time(NULL));

	string affichage = "edge[" + to_string(m) + "][2] = {";

	for (int i = 0; i < m; i++) {

		edge[i][0] = rand()%n;
		edge[i][1] = rand()%n;
		affichage = affichage + "{" + to_string(edge[i][0]) + "," + to_string(edge[i][1]) + "},";
	}

	affichage = affichage.substr(0, affichage.length() - 1) + "}\n";

	cout << affichage;

}

void composantes(int n, int m, int edge[][2], int comp[]) {
	for (int i = 0; i < n; i++) {
		comp[i] = i;
	}
	for (int i = 0; i < m; i++) {
		if (comp[edge[i][0]] != comp[edge[i][1]]) {
			int aux = comp[edge[i][0]];
			for (int z= 0; z < n; z++) {
				if (comp[z] == aux) {
					comp[z] = comp[edge[i][1]];
				}
			}
		}
	}
	string affichage = "Composantes : \n";
	for (int i = 0; i < n; i++) {

		affichage = affichage + "comp(" + to_string(i) + ") = " + to_string(comp[i]) + "\n";
	}

	cout << affichage;

}

void ecritureTailles(int n, int m, int comp[]) {
	int nbIsoles = 0;
	int tailles[n] = {0};
	int composantes[n] = {0};
	for (int i = 0; i < n; ++i)
	{
		tailles[comp[i]] +=1;
	}
	for (int i = 0; i < n; ++i)
	{
		if(tailles[i] != 0) composantes[tailles[i]] +=1;
		if (tailles[comp[i]] == 1) nbIsoles++;
	}
	cout << "Il y a " << nbIsoles << " point(s) isolé(s) \n";
	for (int i = 0; i < n; ++i)
	{
		if(composantes[i] != 0) {
			cout << "Il y a " << composantes[i] << " composante(s) de taille " << i << "\n";
		}
	}
}

int main()
{ 
  int n;     // Nombre de sommets.	
  int m;     // Nombre d'aretes.	
  cout << "Entrer le nombre de sommets:";
  cin >> n;
  cout << "Entrer le nombre d'aretes:";
  cin >> m;
  int edge[m][2];    // Tableau des aretes.
  int comp[n];       // comp[i] est le numero de la composante contenant i.

  grapheRandom(n, m, edge);
  composantes(n, m, edge, comp);
  ecritureTailles(n, m, comp);

  return EXIT_SUCCESS;
}

