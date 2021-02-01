#include <iostream>
#include <string>
#include <algorithm>

#include "matrice.h"

using namespace std;

int valeur(int** E, int i, int j)
{
  if (i >= 0 && j >= 0) {
    return E[i][j];
  } else if (j == -1) {
    return i+1;
  } else if (i == -1) {
    return j+1;
  } else return 0;
}

int min(int a, int b, int c)
{
  return std::min(std::min(a, b), c);
}

int distanceEdition(string s1, string s2, int** E)
{
  int n1 = s1.size();
  int n2 = s2.size();

  int e;
  
  for (int i = 0; i < n1; ++i)
  {
    for (int j = 0; j < n2; ++j)
    {
      s1[i] == s2[j] ? e = 0 : e = 1;
      E[i][j] = min(valeur(E, i-1, j) + 1, valeur(E, i, j-1) + 1, valeur(E, i-1, j-1) + e);
    }
  }

  cout << E[n1-1][n2-1] << endl << s1 << endl << s2 << endl;

  return E[n1-1][n2-1];
}

string alignement(string& s1, string& s2, int** E)
{
  int i = s1.size()-1;
  int j = s2.size()-1;
  string aligne;

  while(i >= 0 && j >= 0) {
    if (valeur(E, i, j) == valeur(E, i-1, j-1) && s1[i] == s2[j]) {
      i--;
      j--;
    }
    else if (valeur(E, i, j) == valeur(E, i-1, j-1) + 1) {
      i--;
      j--;
    }
    else if (valeur(E, i, j) == valeur(E, i-1, j) + 1) {
      s2.insert(j+1, "_");
      i--;
    } 
    else if (valeur(E, i, j) == valeur(E, i, j-1) + 1) {
      s1.insert(i+1, "_");
      j--;
    }
  }

  while(i >= 0) {
    s2.insert(0, "_");
    i--;
  }

  while(j >= 0) {
    s1.insert(0, "_");
    j--;
  }

  for (int i = 0; i < s1.size(); ++i)
  {
    if (s1[i] == s2[i]) {
      aligne.insert(i, "|");
    } else if (s1[i] == '_') {
      aligne.insert(i, "I");
    } else if (s2[i] == '_') {
      aligne.insert(i, "S");
    } else {
      aligne.insert(i, "R");
    }
  }
  
  return aligne;
}

int main(int argc, char** argv)
{

  string s1, s2;
  int** E;
  if (argc < 3)
  {
    cout << "Entrer la première chaîne de caractère : ";
    getline(cin, s1);
    cout << "Entrer la seconde chaîne de caractère : ";
    getline(cin, s2);
  }
  else
  {
    s1 = argv[1];
    s2 = argv[2];
  }

  E = matrice<int>(s1.size(), s2.size());
  int d = distanceEdition(s1, s2, E);

  cout << endl;
  cout << d << endl;
  
  // Décommenter si besoin, pour débugguer :
  // afficheMatrice(s1.size(), s2.size(), E);
  
  string aligne = alignement(s1, s2, E);
  cout << s1 << endl << aligne << endl << s2 << endl;

  delete E;
  return 0;
}
