%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

extern double valeur; // valeur flottante du lexeme
extern double numcar; // position du char

%}

chiffre ([0-9])
%option noyywrap

%%
{chiffre}+\.{chiffre}*|\.{chiffre}+|{chiffre}+ {
	valeur = atof(yytext);
	numcar += yyleng;
	return 300;
}
[ \t] {numcar += 1; /* filtrer les blancs */}
.|\n {numcar += 1; return (int)yytext[0];}
%%
