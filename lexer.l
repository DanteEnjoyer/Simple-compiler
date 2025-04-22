%{
#include "parsertab.hpp"
#include "symtable.h"
int lineno = 1;
%}



%%

[ \t] 	 {}
 \n      {lineno++;}
integer  {yylval = INT;return INTEGER;}
real 	 {yylval = REA;return REAL;}
begin    {return BEGIN_T;}
end 	 {
			return END_T;
		 }
var      {return VAR;}
program  {  
			return PROGRAM;
		}
-?[0-9]+ {
			int ret = addtotable(string(yytext),INT);    
			yylval = ret;
			return NUMBER;
		}
-?[0-9]+"."[0-9]+ {
			int ret = addtotable(string(yytext),REA);    
			yylval = ret;
			return NUMBER;
		}
[+-]		{
			yylval = yytext[0];
			return ADDOP;
		}
"div"	{yylval = '/'; return MULOP;}	
"mod"	{yylval = '%'; return MULOP;}
"="     { yylval = EQ; return RELOP; }     
"<>"    { yylval = NEQ; return RELOP; }    
"<"     { yylval = LT;return RELOP; }    
"<="    { yylval = LEQ;return RELOP; }    
">="    { yylval = GEQ;return RELOP; }    
">"     { yylval = GT;return RELOP; }    
[*/]	{
			yylval = yytext[0];
			return MULOP;
		}
"function" { return FUNCTION;}
"procedure" { return PROCEDURE;}
"read"  {
			return READOP;
		}
"write" {
			return WRITEOP;
		}
"array" {	
			return ARRAY;
		}
"of" 	{
			return OF;
		}
"if"	{
			return IF;
		}
"then"	{
			return THEN;
		}
"else"  {
			return ELSE;
		}
"do"    {
			return DO;
		}
"while" {
			return WHILE;
		}
"or"    {
			yylval = 'o';
			return OR;
		}
"not"   { 
			return NOT;
		}
"and"   {
			yylval = 'a';
			return MULOP;
		}

[a-zA-Z][a-zA-Z0-9]* {
						int p = -1;
						if(context == 1) 
							p = lookup(yytext);
						else
							p = lookup(yytext,localcontext);
						if(p == -1)
							p = addtotable(string(yytext));
						yylval = p;
						return ID;
					}
:=       {
			yylval = '=';
			return ASSIGNOP;
		}

. 		 {return yytext[0];}
%%
int yywrap(void)
{
	return 1;

}
