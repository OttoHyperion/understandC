%{
#include <stdio.h>
#include <string.h>
int yylex();
void yyerror(const char *s);
%}

%union {
	double number;
}

%token <number> NUMBER

%left '+' '-'
%left '*' '/'

%%

expr: term
        | expr '+' term { printf("+"); }
        | expr '-' term { printf("-"); }

term: factor
        | term '*' factor { printf("*"); }
        | term '/' factor { printf("/"); }

factor: NUMBER { printf("%.1f", $1); }
        | '(' expr ')'

%%

void yyerror(const char *s) {
        fprintf(stderr, "%s\n", s);
}

int main(void) {
        yyparse();
        return 0;
}

