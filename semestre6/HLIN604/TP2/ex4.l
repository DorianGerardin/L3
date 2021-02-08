%{
#include <stdio.h>
#include <string.h>

#define IF 301
#define ELSE 302
#define THEN 303
#define THROW 304
#define DEC 305
#define OCT 306
#define HEX 307
#define ID 308
#define FLOAT 309
#define SEP 310
%}

%option noyywrap

%%
if {return IF;}
else {return ELSE;}
then {return THEN;}
throw {return THROW;}
0|[1-9][0-9]* {return DEC;}
0[0-7]* {return OCT;}
0x[0-9A-Fa-f]+ {return HEX;}
[a-z][0-9_a-zA-Z]* {return ID;}
([1-9][0-9]*|0)\.([0-9]*([eE]?[+-]?[1-9][0-9]*)?)? {return FLOAT;}
[\t\n]+ {return SEP;}
"/*"([^*]|"*"+[^*/])*"*"+"/" {return SEP;}
"//".* {return SEP;}
.|\n {return yytext[0]; /* ret le code ASCII pour tout le reste */}
%%

int main(){
	int j; char *invite="Saisissez du code C : ";
	printf(invite);
	while ((j=yylex())!=0) printf("\nJeton : %i; de lexeme %s\n%s",j,yytext,invite);
	return 0; /* 0 en fin de fichier */
}