#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
typedef struct coord{int abs; int ord;} coord;

void pointRandom(int n, coord point[]) {

	srand(time(NULL));

	string affichage = "";

	for (int i = 0; i < n; ++i)
	{
		point[i].abs = rand() % 613;
		point[i].ord = rand() % 793;
		string abs = to_string(point[i].abs);
		string ord = to_string(point[i].ord);
		affichage += "abs : " + abs + ", ord : " + ord + "\n";
	}
	cout << affichage;
}

void distances(int n, int m, coord point[], int edge[][3]) {

	string affichage = "edge[" + to_string(m) + "][3] = {\n";

	int k = 0;

		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{

				int absI = point[i].abs;
				int ordI = point[i].ord;

				int absJ = point[j].abs;
				int ordJ = point[j].ord;

				double distance = 
					(absJ - absI)*(absJ - absI)
					+ 
					(ordJ - ordI)*(ordJ - ordI);

				edge[k][0] = i;
				edge[k][1] = j;
				edge[k][2] = distance;

				affichage = affichage + "{" + to_string(edge[k][0]) + "," + to_string(edge[k][1]) + "," + to_string(edge[k][2]) + "}, \n";

				k++;
			}
	}

	affichage = affichage.substr(0, affichage.length() - 3) + "}\n";

	cout << affichage;
}

void tri(int m, int edge[][3]) {
for (int i = m-1; i > 1; i--)
  {
    for (int j = 0; j < i-1; ++j)
    {
      if(edge[j][2] > edge[j+1][2]) {
        int aux1 = edge[j][0];
        int aux2 = edge[j][1];
        int aux3 = edge[j][2];

        edge[j][0] = edge[j+1][0];
        edge[j][1] = edge[j+1][1];
        edge[j][2] = edge[j+1][2];

        edge[j+1][0] = aux1;
        edge[j+1][1] = aux2;
        edge[j+1][2] = aux3;
      }
    }
  }
}

void affichageApresTri(int m, int edge[][3]) {

	string affichage = "edge[" + to_string(m) + "][3] = {\n";

	for (int i = 0; i < m; ++i) 
	{
		affichage = affichage + "{" + to_string(edge[i][0]) + "," + to_string(edge[i][1]) + "," + to_string(edge[i][2]) + "}, \n";
	}

	affichage = affichage.substr(0, affichage.length() - 3) + "}\n";

	cout << affichage;
}

void kruskal(int n, int edge[][3], int arbre[][2], int comp[]) {
	for (int i = 0; i < n; ++i)
	{
		comp[i] = i;
	}

	int nbAretesACPM = 0;

	for (int j = 0; j < m; ++j)
	{
		if (comp[edge[j][0]] != comp[edge[j][1]]) {
			int aux = comp[edge[j][0]];
			arbre[nbAretesACPM][0] = edge[j][0];
			arbre[nbAretesACPM][1] = edge[j][1];
			nbAretesACPM++;
			for (int z = 0; z < n; ++z)
			{
				if (comp[z] == aux) {
					comp[z] = comp[edge[j][1]];
				}
			}
		}
	}
}

int 
main()
{
  int n;             //Le nombre de points.
  cout << "Entrer le nombre de points: ";
  cin >> n;
  int m=n*(n-1)/2;   // Le nombre de paires de points.
  coord point[n];    // Les coordonnees des points dans le plan.
  int edge[m][3];    // Les paires de points et le carre de leur longueur.
  int arbre[n-1][2]; // Les aretes de l'arbre de Kruskal. 
  int comp[n];

  pointRandom(n, point);
  cout << "Edge non trié \n";
  distances(n, m, point, edge);
  tri(m, edge);
  cout << "Edge trié \n";
  affichageApresTri(m, edge);
  

  return EXIT_SUCCESS;
}
