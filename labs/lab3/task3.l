%{
#include "y.tab.h"
%}

%%

[0-9]+		{ yylval = atoi(yytext); return NUMBER; }
[-+*/()]	{ return *yytext; }
[ \t]		;

%%

int yywrap(void) {
	return 1;
}
