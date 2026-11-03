%{
#include <stdio.h>

int lc=0, sc=0, tc=0, ch=0; /* Global variables */
%}

/* Rule Section */
%%
\n lc++; /* line counter */
([ ])+ sc++; /* space counter */
\t tc++; /* tab counter */
. ch++; /* character counter */
%%

int main()
{
    yylex();

    printf("\nNo. of lines=%d", lc);
    printf("\nNo. of spaces=%d", sc);
    printf("\nNo. of tabs=%d", tc);
    printf("\nNo. of other characters=%d", ch);
}
