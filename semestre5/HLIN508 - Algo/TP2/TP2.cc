#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <string>
#include <algorithm> 
#include "ArbreBinaire.h"

using namespace std;

//------------------------------------------------------
// Inserer un noeud z dans l'arbre A
//------------------------------------------------------

void inserer(ArbreBinaire* A, noeud* z)
{
  noeud* x = A -> racine;
  noeud* p = NULL;

  while(x != NULL) {
    p = x;
    if ((z -> val) < (x -> val)) {
      x = x -> filsG;
    }
    else {
      x = x -> filsD;
    }
  } 
  z -> pere = p;
  if (p == NULL) {
    A -> racine = z;
  }  
  else {
    if ((z -> val) < (p -> val)) {
      p -> filsG = z;
    } else {
      p -> filsD = z;
    }
  }
}

//------------------------------------------------------
// Parcours infixe
//------------------------------------------------------

void parcoursInfixe(noeud* x)
{
  if (x != NULL) {
    parcoursInfixe(x -> filsG);
    cout << x -> val;
    parcoursInfixe(x -> filsD);
  }
}

//------------------------------------------------------
// Noeud de valeur minimale dans l'arbre
//------------------------------------------------------

bool noeudComp(const noeud* n1, const noeud* n2) {
  return n1->val < n2->val;
}


noeud* minArbre(noeud * x)
{
  noeud* minN = x;
  if (x != NULL) {
    noeud* minG = minArbre(x -> filsG);
    noeud* minD = minArbre(x -> filsD);
    noeud* minN = std::min(std::min(minG, minD, noeudComp), x, noeudComp);
  }
  return minN;
}

//------------------------------------------------------
// Recherche d'un noeud de valeur k
//------------------------------------------------------

noeud* recherche(noeud * x, int k)
{
  if (x == NULL) {
    return NULL;
  } else if ((x -> val) == k) {
    return x;
  } else if ((x -> val) > k) {
    return recherche(x -> filsG, k);
  }
  return recherche(x -> filsD, k);
}

//------------------------------------------------------
// Recherche du successeur du noeud x
//------------------------------------------------------

noeud* successeur(noeud *x)
{
  if (x -> filsD != NULL) {
    return minArbre(x -> filsD);
  }
  noeud *y = x -> pere;
  while (y != NULL && x == (y -> filsD)) {
    x = y;
    y = x -> pere;
  }
  return y;
}

//------------------------------------------------------
// Suppression d'un noeud
//------------------------------------------------------

void remplace(ArbreBinaire* A, noeud* x, noeud* z)
{
  noeud* p = x -> pere;
  x -> pere = NULL;
  if (p == NULL) {
    A -> racine = z;
  } else {
    if (x == (p -> filsG)) {
      p -> filsG = z;
    } else {
      p -> filsD = z;
    }
  }
  if (z != NULL) {
    z -> pere = p;
  }
}

void supprimer(ArbreBinaire* A, noeud* z)
{
  if ((z -> filsG) == NULL)
  {
    remplace(A, z, z -> filsD);
  } else if ((z -> filsD) == NULL)
  {
    remplace(A, z, z -> filsG);
  }
  else
  {
    noeud* y = successeur(z);
    remplace(A, y, y -> filsD);
    remplace(A, z, y);
  }
  
  
  
}

//-----------------------------------------------------------------------------
// Main
//-----------------------------------------------------------------------------

int main(){
  ArbreBinaire* arbre = ArbreVide();
  int T[15]={16,6,19,3,1,8,13,5,17,12,14,20,7,23,22};

  // Question 1
  // for(int i=0;i<15;i++){
  //   inserer(arbre, creerNoeud(T[i]));
  // }
  // //dessinArbre(arbre, "exemple");
  // affichageGraphique(arbre);
  

  // Question 2
  
  cout << "Parcours infixe de l'arbre : ";
  parcoursInfixe(arbre->racine);
  cout << endl;
  noeud* min=minArbre(arbre->racine);
  if(min!=NULL)
    cout << "Valeur minimale présente dans l'arbre: "<< min->val << endl;
  else
    cout<< "Arbre vide..." << endl;
  
 
  // Question 3
 
  /*
  int k1;
  while (true) {
     cout << "Rentrer une valeur à rechercher (< 0 pour quitter) : ";
     cin >> k1;
     if (k1 < 0) break;
     noeud* rech=recherche(arbre,k1);
     cout << "Recherche de la valeur " << k1 << " : ";
     if(rech) cout << "trouvée (vérification : " << (rech->val) << ")" << endl;
     else     cout << "non trouvée" << endl;
  }
  */

  // Question 4 
 
  /*
  int k2;
  while (true) {
     cout << "Rentrer la valeur dont on doit trouver le successeur (< 0 pour quitter) : ";
     cin >> k2;
     if (k2 < 0) break;
     noeud* rech=recherche(arbre,k2);
     if (rech) {
       cout << "Successeur de la valeur " << k2 << " : ";
       noeud* s = successeur(rech);
       if (s) cout << s->val << endl;
       else cout << rech->val << " est la valeur max !"<<endl;
     } else cout << "Valeur "<< k2 <<" non présente..." << endl;
  }
  */
 
  // Question 5
 
  /*
  int k3;
  while (true) {
     cout << "Rentrer la valeur du noeud à supprimer (< 0 pour quitter) : ";
     cin >> k3;
     if (k3 < 0) break;
     noeud* rech = recherche(arbre, k3);
     if(rech) {
       supprimer(arbre, rech);
       dessinArbre(arbre, "supprime-" + to_string(k3));
       affichageGraphique(arbre);
     } 
     else cout << "Valeur " << k3 << " non présente" << endl;
  }

  */
  
  return 0;

}
