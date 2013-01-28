
%%

(int|void|char)(" "?*" "?)?[^;\n]+/(";"|\n) { printf("variable reconnu : %s\n", yytext); }
(.|\n) {}
