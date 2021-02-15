%{
#include <stdio.h>
#include <string.h>

int niveau = 0; // niveau d'indentation de 0 à n-1
int tab[10]; //on memorise le nb de blancs de chaque niveau
%}

%option noyywrap
%s DANSLISTE

%%
^\n[ \t]*[-*] {
	BEGIN(DANSLISTE);
	niveau = 0;
	tab[niveau] = yyleng-2; //nb blancs au début (2 pour \n et *)
	puts("<ul><li>")
}
<DANSLISTE>^[ \t]*[*-] {
	puts("</li>");
	int diff=(yyleng-1)-tab[niveau]; //(1 pour *)
	if (diff == 0 || diff == 1) {
		puts("<li>");
	} else if (diff >= 2) { // sous liste
		puts("<ul><li>");
		niveau++;
		tab[niveau] == yyleng-1; // (1 pour *)
	} else {
		do {
			puts("</ul>") //fermer
			niveau--;
		} while(niveau > 0 && tab[niveau] > yyleng-1);
	}
}
%%

int main() {

}
