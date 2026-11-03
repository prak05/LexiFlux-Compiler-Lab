#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char input[100];
int i=0;
int e(),ep(),t(),tp(),f();

void main(){
printf("\nRecursive Descent parsing for the following Grammer\n");
printf("\nE->TE'\nE'->+TE'/@\nT->FT'\nT'->*FT'/@\nF->(E)/id\n");

printf("Enter the string to be checked ");
scanf("%s",input);
if(e())
{
 if(input=='\0')
 printf("\nString is accepted\n");
 else 
  printf("\nString isnot accepted\n");
  }
  else 
    printf("\nString isnot accepted\n");
    }
int e()
{
if(t())
{
if(ep())
{
return 1;
else 
return 0;
}
else
return 0;
}

int ep()
{
if(input[i]=='+')
{
i++;

if(t())
{if(ep())
return 1;
else 
return 0;
}
else
return 0;
}
else 
return 1;
}
int t()
{
if(f())
{
if(tp())
return 1;
else 
return 0;
}
else 
return 0;
}
int tp()
{
if(input=='*')
{
i++;
if(fp()){
if(tp())
return 1;
else 
return 0;
}
else 
return 0;
}
else 
return 1;
}

int f()
{
if(input=='(')
{
i++;
if(e())
{if(input==')')
{i++;
return 1;
}
else 
return 0;
}
else
return 0;
}
else if((input[i]>='a'&&input[i]<='z')||(input[i]>='A'&&input[i]<='z')){
i++;
return 1;
}
else
return 0;
}

