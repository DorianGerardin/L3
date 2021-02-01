#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <string>
#include <time.h>

using namespace std;

const int N=1400;
const int M=(N*(N-1))/2;
  
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

float distance(coord p1,coord p2) {

  int absI =p1.abs;
  int ordI = p1.ord;

  int absJ = p2.abs;
  int ordJ = p2.ord;

  float distance = 
    (absJ - absI)*(absJ - absI)
    + 
    (ordJ - ordI)*(ordJ - ordI);

  return sqrt(distance);

}


void voisins(int n,int dmax,coord point[],vector<int> voisin[],int &m) {

  m = 0;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (distance(point[i], point[j]) <= dmax) {
        voisin[i].push_back(j);
        voisin[j].push_back(i);
        m++;
      }
    }
    
  }
  
}
void voisins2arete(int n,vector<int>voisins[],int arete[][2]) {



}
void affichageGraphique(int n,int m,coord point[],int arete[][2],string name) {

  ofstream output;                           
  output.open(name,ios::out);
  output << "%!PS-Adobe-3.0" << endl;
  output << "%%BoundingBox: 0 0 612 792" << endl;
  output << endl;  
  for(int i=0;i<n;i++)
    {
      output << point[i].abs << " " << point[i].ord << " 3 0 360 arc" <<endl;
      output << "0 setgray" <<endl;
      output << "fill" <<endl;
      output << "stroke"<<endl;
      output << endl;
    }
  output << endl;
  for(int i=0;i<m-1;i++)
   {
     output << point[arete[i][0]].abs << " " << point[arete[i][0]].ord 
	    << " moveto" << endl;
     output << point[arete[i][1]].abs << " " << point[arete[i][1]].ord
	    << " lineto" << endl;
     output << "stroke" << endl;
     output << endl;
   }
  output << "showpage";
  output << endl;

}
bool existe(int n,float dis[],bool traite[],int &x);

void dijkstra(int n,vector<int> voisin[],coord point[],int pere[]) {

  float dis[n];
  bool traite[n];
  for (int i = 0; i < n; i++)
  {
    dis[i] = INT32_MAX;
    traite[i] = false;
  }
  int racine = 0;
  pere[racine] = racine;
  dis[racine] = 0;
  int sommetCourant;
  while (existe(n, dis, traite, sommetCourant))
  {
    for (int i = 0; i < voisin[sommetCourant].size(); i++)
    {
      int voisinSC = voisin[sommetCourant].at(i);
      if (!traite[voisinSC] && 
        dis[voisinSC] > dis[sommetCourant]
        + distance(point[sommetCourant], point[voisinSC]))
      {
        pere[voisinSC] = sommetCourant;
        dis[voisinSC] = distance(point[sommetCourant], point[voisinSC]);
      }
    }
  }
}

int construireArbre(int n,int arbre[][2],int pere[]);

int
main()
{
  int n;                           // Le nombre de points.
  cout << "Entrer le nombre de points: ";
  cin >> n; 
  int dmax=50;                     // La distance jusqu'a laquelle on relie deux points.
  coord point[N];                  // Les coordonnees des points.
  vector<int> voisin[N];           // Les listes de voisins.          
  int arbre[N-1][2];               // Les aretes de l'arbre de Dijkstra.
  int pere[N];                     // La relation de filiation de l'arbre de Dijkstra.
  int m;                           // Le nombre d'aretes
  int arete[M][2];                 // Les aretes du graphe
  return EXIT_SUCCESS;
}
