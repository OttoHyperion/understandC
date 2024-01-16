%{
#include "y.tab.h"
%}

%%

[0-9]+(\.[0-9]+)?          { yylval.number = atof(yytext); return NUMBER; }
[-+*/()]        return *yytext;
[ \t]           ;

%%

int yywrap(void) {
        return 1;
}
