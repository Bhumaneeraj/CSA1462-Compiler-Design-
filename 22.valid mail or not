%{
%}
%%
[a-z.0-9]+@[a-z]+(.com|.in) {printf("valid email id");}
.+ {printf("not a valid email id");}
%%
int yywrap(){}
int main()
{
printf("enter a email id");
yylex();
}
