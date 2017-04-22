
%{
#include<stdio.h>
#include"lex.yy.c"
int yyerror(char *);
int yywrap();
%}

%token NUMBER
%%
exp:exp '+' NUMBER { $$ = $1 + $3;
			printf("Recognised '+' expression.\n");
		     }
	 |exp '-' NUMBER { $$ = $1 + $3;
			printf("Recognised '-' expression.\n");
		     }
	 |NUMBER     { $$ = $1;
			printf("Recognised a number.\n");
		     } 

%%
int main(void)
{
	return yyparse();
}

int yyerror(char *msg)
{
	return fprintf(stderr,"YACC: %s\n",msg);
}

int yywrap()
{
	return -1;
}
