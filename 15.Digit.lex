%%
[0-9]+ { printf("valid digit"); }
.* { printf("invalid digit"); }
%%

int yywrap ()
{
	return 1;

}

int main()
{
	printf("Enter the input;");
	yylex ();
}
