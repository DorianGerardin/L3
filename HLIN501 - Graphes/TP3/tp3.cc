#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void voisinsRandom(int n, int m, vector<int> voisins[]) {

	srand(time(NULL));

	int x,y;
  	for(int i = 0; i < m; i++) {
	    do {
	      x = rand() % n;
	      y = rand() % n;
	    }
	    while(x == y || find(voisins[x].begin(),voisins[x].end(),y) != voisins[x].end());
	    voisins[x].push_back(y);
	    voisins[y].push_back(x);
  	}
}

void parcoursLargeur(int n, vector<int> voisins[], int niveau[], int ordre[], int pere[]) {

	int r = 0;
	int dejaVus[n] = {0}; 

	dejaVus[r] = 1;
	ordre[r] = 1;
	pere[r] = r;
	niveau[r] = 0;

	

}

int
main()
{
  int n;                                    // Le nombre de sommets.
  int m;                                    // Le nombre d'aretes.
  cout << "Entrer le nombre de sommets: ";
  cin >> n;
  cout << "Entrer le nombre d'aretes: ";
  cin >> m;
  vector<int> voisins[n];                   // Les listes des voisins. 
  int pere[n];                              // L'arbre en largeur.
  int ordre[n];                             // L'ordre de parcours.
  int niveau[n];                            // Le niveau du point.

  voisinsRandom(n, m, voisins);

  return EXIT_SUCCESS;
}
