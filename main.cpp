#include <iostream>
#include <fstream>
#include "symtable.h"

extern int yyparse();
extern FILE *yyin;
extern int yylex();


int main(int argc, char **argv) {
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        cout << "Error: Could not open file " << argv[1] << endl;
        return 1;
    }
    init_symtable();
	yyparse();
	//emit_begend(2);
    print_symtable(symtable);
    //int token;
    //while ((token = yylex()) != 0) {
    //    std::cout << "Odczytano token: " << token << std::endl;
    //}
    fclose(yyin);
    yylex_destroy();
    return 0;
}
