%{
int ln=0;
%}
%%
.* {ln++;fprintf(yyout,"\n%d:%s",ln,yytext);}
%%
int yywrap(){}
int main()
{
yyin=fopen("simple.txt", "r");
yyout=fopen("outnew1.txt","w");
yylex();
}
