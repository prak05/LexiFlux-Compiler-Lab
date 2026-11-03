%{
#include<stdio.h>
#include<stdlib.h>
int lc=0, sc=0, tc=0, ch=0;
%}
%%
\n lc++;
([ ])+ sc++;
\t tc++;
. ch++;
%%
int main()
{
printf("enter input string:");
yylex();
printf("\n no of lines=%d",lc);
printf("\n no of spaces=%d",sc);
printf("\n no of tabs=%d",tc);
printf("\n no of other characters=%d",ch);
}
int yywrap()
{
return(1);
}
