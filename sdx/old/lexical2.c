#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char keyword[32][10] = {"void", "main", "int"};
int iskeyword(char buffer[])
{int i, flag = 0;
 for (i = 0; i < 32; i++)
{if (strcmp(keyword[i], buffer) == 0)
{flag = 1;
break;
}}
return flag;
}
int main()
{char ch, buffer[15];
char operators[] = "+-*%=";
FILE *fp;
int i, j = 0;
 fp = fopen("program.txt", "r");
if (fp == NULL)
{printf("File can't be opened\n");
exit(0); }
 while ((ch = fgetc(fp)) != EOF)
{for (i = 0; i < 5; i++)
{if (ch == operators[i])
 {printf("%c is operator\n", ch);
 break; }}
if (isalnum(ch))
{buffer[j++] = ch;}
else if ((ch == ' ' || ch == '\n' || ch == ';') && (j != 0))
{buffer[j] = '\0';
j = 0;
if (iskeyword(buffer))
 printf("%s is keyword\n", buffer);
else
 printf("%s is identifier\n", buffer);}}
fclose(fp);
return 0;}
