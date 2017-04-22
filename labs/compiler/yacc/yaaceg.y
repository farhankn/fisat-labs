
%{
#include<stdio.h>
#include"lex.yy.c"
int yyerror(char *);
int yywrap();
%}

%token NUMBER

%%
result	:e'\n'{printf("Output : %d\n\n",$$); 
	exit(0);};

e	:e '+' t { $$ = $1 + $3;}
	|e '-' t { $$ = $1 - $3;}
	|t     { $$ = $1;};
			 
t	:t '*' f { $$ = $1 * $3;}
	|t '/' f { $$ = $1 / $3;}
	|f     { $$ = $1;};

f	: '('e')'{$$ = $2;}
	|NUMBER{$$ = $1;};
			 
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
