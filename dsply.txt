%{
#include<stdio.h>
int lc=0, sc=0, tc=0, ch=0; /*Global variables*/
%}
/*Rule Section*/
%%
\n lc++; //line counter
([ ])+ sc++; //space counter
\t tc++; //tab counter
. ch++; //characters counter
%%
int main() {
    yylex();
    printf("\nNo. of lines=%d\nNo. of spaces=%d\nNo. of tabs=%d\nNo. of other characters=%d", lc, sc, tc, ch);
}
int yywrap() 
{ 
return 1; 
}
