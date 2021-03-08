/** @file analdesc.c        
 *@author Michel Meynard
 *@brief Analyse descendante récursive d'expression arithmétique
 *
 * Ce fichier contient un reconnaisseur d'expressions arithmétiques composée de 
 * littéraux entiers sur un car, des opérateurs +, * et du parenthésage ().
 * Remarque : soit rediriger en entrée un fichier, soit terminer par deux 
 * caractères EOF (Ctrl-D), un pour lancer la lecture, l'autre comme "vrai" EOF.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
                             /* les macros sont des blocs : pas de ';' apres */
#define AVANCER {jeton=yylex();}
#define TEST_AVANCE(prevu) {if (jeton==(prevu)) AVANCER else ERREUR_SYNTAXE}
#define ERREUR_SYNTAXE {printf("\nMot non reconnu : erreur de syntaxe \
au caractère numéro %d \n",numcar); while(jeton !='\n') AVANCER; erreur=1;} 
#define INVITE "Veuillez saisir une expression arithmétique infixée ou q pour quitter SVP : \n"

double valeur; //var globale utilisé par flex
int jeton;     //caractere courant du flot d'entrée
int numcar;    //numéro du caractère courant (jeton)
int erreur;    //booleen indiquant s'il y a eu une erreur

int yylex();
void X(); double E(); double R(); double T(); double S(double);
double F(); double G(); double C();

int jeton;                       /* caractère courant du flot d'entrée */
int numcar=0;                    /* numero du caractère courant (jeton) */

void X() {
  numcar = 1; erreur = 0; double r;
  if (jeton == 'q') {
    AVANCER;
    if (jeton == '\n') return;
    else {
      ERREUR_SYNTAXE;
      X();
    }
  } else {
    r = E();
    if (!erreur && jeton == '\n') {
      printf("Resultat : %.2f\n\n", r);
    } else if (!erreur) {
      ERREUR_SYNTAXE;
    }
    printf(INVITE);
    AVANCER;
    X();
  }
}

double E() {
  return R(T());
}

double R(double tg){
  if (jeton=='+') {             /* regle : R->+TR */
    AVANCER
    return R(tg + T());
  }
  else if (jeton == '-') {
    AVANCER;
    return R(tg - T());
  } 
  return tg;        
}

double T(void){
  return S(F());                /* regle : T->FS */
}

double S(double g){
  if (jeton=='*') {             /* regle : S->*FS */
    AVANCER
    return S(g * F());
  }
  else return g;                        /* regle : S->epsilon */
}

double F(){
  return C(G());
}

double C(double gg){
  if (jeton == '^') {
    AVANCER;
    return pow(gg, C(G()));
  } else return gg;
}

double G() {
  double e = 0;
  if (jeton == '(') {
    AVANCER;
    e = E();
    TEST_AVANCE(')');
  } else if (jeton == 300) {
    e = valeur;
    AVANCER;
  } else ERREUR_SYNTAXE;
  return 0;
}

int main(void){                 /* Fonction principale */
  printf(INVITE);
  AVANCER			/* initialiser jeton sur le premier car */
  E();                          /* axiome */
  return 0;
}