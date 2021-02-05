/**
 * @file afd.h     
 * @author Michel Meynard
 * @brief Définition d'un AFD
 */
#define EINIT 0
#define ESEP 1
#define EI 2
#define EENT 3
#define EP 4
#define ES 5
#define ESE 6
#define EIF 7
#define EFLOAT 8
#define ESS 9
#define ESEE 10
#define EID 11
#define ECOM 12
#define ELITCH 13
#define NBETAT 6

int TRANS[NBETAT][256];		/* table de transition : état suivant */
int JETON[NBETAT];		/* jeton à retourner */

int creerAfd(){			/* Construction de l'AFD */
  int i;int j;			/* variables locales */
  for (i=0;i<NBETAT;i++){
    for(j=0;j<256;j++) TRANS[i][j]=-1; /* init vide */
    JETON[i]=0;			/* init tous états non finaux */
  }
  classe(EINIT, '0', '9', EENT);
  classe(EENT, '0', '9', EENT);
  TRANS[EENT]['.'] = EFLOAT;
  TRANS[EINIT]['.'] = EP;
  classe(EP, '0', '9', EFLOAT);
  classe(EFLOAT, '0', '9', EFLOAT);
  JETON[EENT] = 300 + EENT;
  JETON[EFLOAT] = 300 + EFLOAT;

  // Je n'ai pas pu continué car j'ai regardé la correction
  // Et je n'avais pas trop compris le principe au début

  //litChaine
  TRANS[EINIT]['"'] = EG;
  classe(EG, 0, 255, EG);
  TRANS[EG]['"'] = ELITCH;
  JETON[ELITCH] = 300 + ELITCH;
}

void classe(int ed, int cd, int cf, int ef) {
  while (cd != cf) {
    TRANS[ed][cd] = ef;
    cd++;
  }
  TRANS[ed][cf] = ef;
}