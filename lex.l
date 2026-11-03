%{
#include <stdio.h>
#include <stdlib.h>
int line_no = 1;
%}

%option noyywrap

%%
\n              { line_no++; }
[ \t]+          { /* ignore whitespace */ }

"("             { printf("Line %d: OPEN PARENTHESIS -> %s\n", line_no, yytext); }
")"             { printf("Line %d: CLOSE PARENTHESIS -> %s\n", line_no, yytext); }

"int"|"float"|"char"|"return"|"if"|"else" { 
    printf("Line %d: KEYWORD -> %s\n", line_no, yytext); 
}

[a-zA-Z_][a-zA-Z0-9_]* { 
    printf("Line %d: IDENTIFIER -> %s\n", line_no, yytext); 
}

[0-9]+(\.[0-9]+)? { 
    printf("Line %d: NUMBER -> %s\n", line_no, yytext); 
}

"+"|"-"|"*"|"/"|"=" { 
    printf("Line %d: OPERATOR -> %s\n", line_no, yytext); 
}

[{},;] { 
    printf("Line %d: DELIMITER -> %s\n", line_no, yytext); 
}

. { 
    printf("Line %d: UNKNOWN -> %s\n", line_no, yytext); 
}
%%

int main() {
    yylex();
    return 0;
}
