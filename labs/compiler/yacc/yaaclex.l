%{
#include"yaaceg.tab.h"
extern int yylval;
%}

%%
([0-9])+		{yylval = atoi(yytext);
			return NUMBER;}
[\t]		{}
\n		{printf("\n");return yytext[0];}
[^0-9]		{return yytext[0];}

%% 
