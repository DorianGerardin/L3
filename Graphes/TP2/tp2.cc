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

	int compt = 0;

	for (int k = 0; k < m; ++k)
	{
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

				edge[compt][0] = i;
				edge[compt][1] = j;
				edge[compt][2] = distance;

				compt++;

			}
		}
		affichage = affichage + "{" + to_string(edge[k][0]) + "," + to_string(edge[k][1]) + "," + to_string(edge[k][2]) + "}, \n";
	}

	affichage = affichage.substr(0, affichage.length() - 3) + "}\n";

	cout << affichage;
}

void tri(int m, int edge[][3]) {
	int aux[3] = {0};
	int aux2[3] = {0};
		for (int i = 0; i < m - 1; ++i)
		{
			if (edge[i][2] > edge[i+1][2]) {
				aux[3] = edge[i];
				edge[i] = edge[i+1];
				edge[i+1] = aux;
				if (edge[i][2] < edge[i-1][2]) {
					for (int j = i; j > 0; j--)
					{
						if (edge[j][2] < edge[j-1][2]) {
							aux2[3] = edge[j];
							edge[j] = edge[j-1];
							edge[j-1] = aux2;
						}
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

  pointRandom(n, point);
  tri(m, edge);
  distances(n, m, point, edge);

  return EXIT_SUCCESS;
}
