/**
 * @file analex.c  
 * @author Michel Meynard
 * @brief Prog principal appelant analex()
 */
#include <stdio.h>
#include <string.h>
#include "afd.h"		/* Définition de l'AFD et des JETONS */
#include "analex.h"		/* Définition de la fon : int analex() */

int main(){			/* Construction de l'AFD */
  int j;			/* jeton retourné par analex() */
  char *invite="Code C SVP : ";
  creerAfd();			/* Construction de l'AFD à jeton */
  printf("%s",invite);		/* prompt */
  while((j=analex())){		/* analyser tq pas jeton 0 */
    printf("\nRésultat : Jeton = %d ; Lexeme = %s\n%s",j,lexeme,invite);
  }
  return 0;
}