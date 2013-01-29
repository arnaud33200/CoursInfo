ALL (.|\n)

%%

"/*"([^*]|"*"[^/])*"*/" { printf("%s\n", yytext); }
"//".* { printf("%s\n", yytext); }
{ALL} {}

