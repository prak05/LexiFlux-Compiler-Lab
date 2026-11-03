%{
#include<stdio.h>
int vow=0, con=0;
%}
%%
[\t\n]+ ;
[aeiouAEIOU] {vow++;}
[a-zA-Z]     {con++;}
%%
int main()
{
printf("Enter some input string:\n");
yylex();
printf("No:of vowels = %d\n", vow);
printf("No:of consonants = %d\n", con);
 return 0;
}
int yywrap()
{
    return 1;
}
