/** @file exReg.c
 *@author Tristan Tribes (Modèle M. Meynard)
 *@brief TDTP7
**/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "arbin.h"
                             /* les macros sont des blocs : pas de ';' apres */
#define AVANCER {jeton=getchar();numcar++;}
#define TEST_AVANCE(prevu) {if (jeton==(prevu)) AVANCER else ERREUR_SYNTAXE}
#define ERREUR_SYNTAXE {printf("\nMot non reconnu : erreur de syntaxe au caractère numéro %d (caractère ASCII : %d)\n",numcar, jeton); exit(1);}

Arbin S(); Arbin X(); Arbin E(); Arbin R(); Arbin T(); Aribin Y(); Arbin F()

int jeton;                       /* caractère courant du flot d'entrée */
int numcar=0;                    /* numero du caractère courant (jeton) */
Arbin resultat=null;                 /* Resulat total */

Arbin union() {return runion(concat());}

Arbin S() {
  Arbin g;
  g=E();
  return X(g);
}

Arbin E() {
	Arbin g;
	g=T();
	return R(g);
}

Arbin R(Arbin g) {
	Arbin d;
	if (jeton =='(' || islower(jeton) || jeton =='0' || jeton == '@') {
		
	}
}

Arbin F() {
}

int main(void){                 /* Fonction principale */
  AVANCER			/* initialiser jeton sur le premier car */
  resultat = union();                          /* axiome */
  if (jeton==EOF) {             /* expression reconnue et rien après */
    printf("\nMot reconnu\n");
    ab_afficher(resultat);
  }
  else {
    ERREUR_SYNTAXE           /* expression reconnue mais il reste des car */
  }
  return 0;
}
