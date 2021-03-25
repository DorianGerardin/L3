/** @file exReg.c
 *@author Tristan Tribes (Modèle M. Meynard)
 *@brief TDTP7
**/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "arbin1.c"
                             /* les macros sont des blocs : pas de ';' apres */
#define AVANCER {jeton=getchar();numcar++;}
#define TEST_AVANCE(prevu) {if (jeton==(prevu)) AVANCER else ERREUR_SYNTAXE}
#define ERREUR_SYNTAXE {printf("\nMot non reconnu : erreur de syntaxe au caractère numéro %d (caractère ASCII : %d)\n",numcar, jeton); exit(1);}

void axiome(void);Arbin union(void);Arbin runion(Arbin);Arbin concat(void);Arbin rconcat(Arbin);Arbin etoile(void);Arbin retoile(Arbin);Arbin facteur(void);/* déclars */

int jeton;                       /* caractère courant du flot d'entrée */
int numcar=0;                    /* numero du caractère courant (jeton) */
Arbin resultat=null;                 /* Resulat total */

Arbin union() {return runion(concat());}

Arbin runion(Arbin gauche) {
  if (jeton=='|') {
    AVANCER
    return runion(ab_construire('|', gauche, concat()));
  } else {
    return gauche;
  }
}

Arbin concat() {return rconcat(concat());}

Arbin rconcat(Arbin gauche) {
  if((jeton>=97 && jeton<=122) || jeton=='@' || jeton=='0') {
    AVANCER
    return rconcat(ab_construire('.', gauche, concat()));
  }
}

Arbin etoile() {return retoile(concat());}

Arbin retoile(Arbin gauche) {
  if (jeton=='*') {
    AVANCER
    return retoile(ab_construire('*', gauche, concat()));
  } else {
    return gauche;
  }
}


Arbin facteur(void){
  if (jeton=='(') {
    AVANCER
    Arbin pArbre = union();
    TEST_AVANCE(')')
    return valeur;
  }
  else
    if ((jeton>=97 && jeton<=122) || jeton=='@' || jeton=='0') {
      Arbin arbinTerm = ab_construire(jeton, null, null);
      AVANCER
      return arbinTerm;
    }
    else ERREUR_SYNTAXE
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
