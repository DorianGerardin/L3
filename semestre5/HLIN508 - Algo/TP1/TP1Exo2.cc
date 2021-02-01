#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "tgmath.h"
#include "AffichageMaisons.h"

#define dcouv 100

void GenererMaisons(int n, int coordMaisons[][2])
{
  for(int i=0;i<n;i++)
  {
    coordMaisons[i][0]=10+rand()%593;
    coordMaisons[i][1]=10+rand()%773;
  }
}

void Initialiser(int n, int a[])
{
  for(int i=0;i<n;i++) a[i]=0;
}

bool Couvre(int i, int j, const int coordMaisons[][2])
{

  int absI = coordMaisons[i][0];
  int ordI = coordMaisons[i][1];

  int absJ = coordMaisons[j][0];
  int ordJ = coordMaisons[j][1];

  double distance = sqrt(
                      (absJ - absI)*(absJ - absI)
                      + 
                      (ordJ - ordI)*(ordJ - ordI)
                    );
  return distance < dcouv;
}

int ChoixProchaineMaison(int n, const int coordMaisons[][2], int dejaCouvertes[])
{
  int max = 0;
  int mMax = 0;
  for (int i = 0; i < n; ++i) {
    int mI = 0;
    for (int j = 0; j < n; ++j)
    {
      if (Couvre(i, j, coordMaisons) && dejaCouvertes[j] == 0) {
        mI++;
      }
    }
    if (mI > mMax) {
      mMax = mI;
      max = i;
    }
    dejaCouvertes[n] += mMax;
  }
  return max;
}

int ChoixEmetteurs(int n, const int coordMaisons[][2], int emetteurs[])
{
  int nbEmetteurs = 0;
  int dejaCouvertes[n+1] = {0}; 
  while (dejaCouvertes[n] < n) {
    int choix = ChoixProchaineMaison(n, coordMaisons, dejaCouvertes);
    emetteurs[choix] = 1;
    nbEmetteurs++;
    for (int i = 0; i < n; ++i)
    {
      if (Couvre(choix, i, coordMaisons) && dejaCouvertes[i] == 0) {
        dejaCouvertes[i] = 1;
      }
    }
  }
  return nbEmetteurs;
}

int suivant(int n, int tab[])
{
  int i = 0;
  while (i < n and tab[i] == 1) tab[i++]  = 0;
  if (i == n) return 1;
  tab[i] = 1;
  return 0;
}

int ChoixEmetteursOpt(int n, const int coordMaisons[][2], int emetteurs[])
{
  //
  // A COMPLETER
  //
  return 0;
}

int main(int argc, char** argv)
{
  int n;
  if (argc < 2)
  {
    cout << "Entrer le nombre de maisons: ";
    cin >> n;
  }
  else
  {
    n = atoi(argv[1]);
  }
  
  srand(time(NULL));

  int coordMaisons[n][2]; // coordonnées des maisons dans le plan
  int emetteurs[n];       // numéro des maisons que l'on choisit pour placer des émetteurs

  GenererMaisons(n, coordMaisons);
  AffichageMaisons(n, coordMaisons, "Maisons");
  Initialiser(n, emetteurs);

  int nbEmetteurs = ChoixEmetteurs(n, coordMaisons, emetteurs);
  cout << "Nombre d'émetteurs placés : "<< nbEmetteurs << endl;
  AffichageMaisonsEmetteurs(n, coordMaisons, emetteurs, "Emetteurs");

  int emetteursOpt[n];
  Initialiser(n, emetteursOpt);
  int nbEmetteursOpt = ChoixEmetteursOpt(n, coordMaisons, emetteursOpt);
  cout << "Nombre d'émetteurs optimal : " << nbEmetteursOpt << endl;
  AffichageMaisonsEmetteurs(n, coordMaisons, emetteursOpt, "EmetteursOpt");

  return 0;
}

#undef dcouv
