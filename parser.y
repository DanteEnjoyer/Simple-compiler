%debug
%{
	#include "symtable.h"
	#include <cmath>
	int yylex();
	void yyerror(const char *s);
	void gencode(char op, int arg1, int arg2,string tname);
	int add_temptotable(ValueType vtype);
	void emit(string command, int arg1, int arg2, int output, int arg_count);
	int convert_to_propertype(int arg1,int arg2);
	int convert_to_assignment(int lside, int assignment);
	int addlabel();
	string determine_type(int arg1);
	int add_referencetotable(ValueType vtype, int cont,int offs);
	int tempno = 0;
	int context = 1;
	int localcontext = 1;
	int negoffset = 0;
	bool addressReference = false;
	int functionaloffset = 8; // 12 dla funkcji
	string determine_offset(int ind,string command );
	void printAndClearFunctionBody();
	vector<int> help;
	vector<int> help_exp;	
	vector<int> args;
	vector<string> function_body;
%}

%token BEGIN_T
%token END_T
%token NUMBER
%token INTEGER
%token REAL
%token ID
%token PROGRAM
%token VAR
%token ASSIGNOP
%token ADDOP
%token MULOP
%token RELOP
%token INPUT_OUTPUT
%token READOP
%token WRITEOP
%token ARRAY
%token OF
%token IF
%token WHILE
%token DO
%token ELSE
%token THEN
%token OR
%token NOT
%token FUNCTION
%token PROCEDURE
%token EQ
%token NEQ
%token LT
%token LEQ
%token GEQ
%token GT
%%
start: program	

program:
    PROGRAM ID '(' ID ',' ID ')' ';' {incrementoffset(12);}
    declarations {emit_begend(1);}subprogram_declarations {cout << "lab0:" << endl;}
    compound_statement '.' {emit_begend(2);}
    ;

declarations:
    VAR declaration_list declarations
    | %empty
    ;

declaration_list:
    declaration
    | declaration_list ';' declaration
    ;

declaration:
    identifier_list ':' type ';' {
									if(context ==1)
									{
										vector<int>::iterator ids;
										ValueType v;
										if($3 <= REA || $3<= INT)
										{
											if($3 == INT)
											{
												v = INT;
											}
											else 
												v = REA;
											for(ids = help.begin(); ids != help.end(); ids++)
											{
												modifyidentifier(*ids, v);
											}
										}
										else
										{
											$3 = $3-REA-INT;
											v = symtable[$3].vtype;
											for(ids = help.begin(); ids != help.end(); ids++)
											{
												modifyarray(*ids, v,symtable[$3].arr.size,$3);
											}
										}
										help.clear();
									}
									else
									{
										vector<int>::iterator ids;
										ValueType v;
										if($3 <= REA || $3<= INT)
										{
											if($3 == INT)
											{
												v = INT;
											}
											else 
												v = REA;
											for(ids = help.begin(); ids != help.end(); ids++)
											{
												if(v == REA)
													negoffset -= 8;
												else 
													negoffset -= 4;
												modifyidentifier(*ids, v,negoffset,localcontext);
											}
										}
										else
										{
											$3 = $3-REA-INT;
											v = symtable[$3].vtype;
											for(ids = help.begin(); ids != help.end(); ids++)
											{
												if(v == REA)
													negoffset -= 8*symtable[$3].arr.size;
												else 
													negoffset -= 4*symtable[$3].arr.size;
												modifyarray(*ids, v,symtable[$3].arr.size,$3,negoffset,localcontext);
											}
										}
										help.clear();									
									}
								 }
    ;
type:
	standard_type {$$ = $1;}
	| ARRAY '[' NUMBER '.''.' NUMBER']' OF standard_type {
															ValueType v;
															if($9 == REA)
																v = REA;
															else
																v = INT;
															int v1 = stoi(symtable[$3].name);
															int v2 = stoi(symtable[$6].name);
															$$ = addnonetotable(v1, v2, v)+INT+REA;
														 }
	;
standard_type:
	INTEGER {$$ = $1;}
	| REAL	{$$ = $1;}
	;
identifier_list:
    ID							{
									help.push_back($1);
									if(context > 1)
										args.push_back($1);
								}
    | identifier_list ',' ID	{
									help.push_back($3);
									if(context > 1)
										args.push_back($3);
								}
    ;
subprogram_declarations:
	subprogram_declarations subprogram_declaration';'
	| %empty
	;
subprogram_declaration:
	subprogram_head  declarations  compound_statement {
														context--; 
														negoffset=0;
														printAndClearFunctionBody();
														args.clear();
													  }
;													  
subprogram_head:
	FUNCTION ID 
				{
					emit(symtable[$2].name+string(":"),-1,-1,-1,0);
					localcontext++;
					context++;
					$1 = addfunctotable($2,localcontext,8);
					functionaloffset = 12;
					
				}
	arguments ':' standard_type';'
				{
					if($6 == REA)
					{
						symtable[$2].vtype = REA;
					}
					else if ($6 == INT)
						symtable[$2].vtype = INT;
					//cout << ValueTypeToString(symtable[$2].vtype) << symtable[$1].vtype<<endl;
					if($4 != -1)
					{
						vector<int>::iterator ids;
						for(ids = args.end()-1; ids >= args.begin(); ids--)
							{
								//cout << symtable[*ids].name<<endl;
								symtable[$1].function_args.push_back(*ids);
								modifyreference(*ids,functionaloffset);
								functionaloffset +=4;
							}
						help.clear();
					}
					$$ = $1;
				}
				
	| PROCEDURE ID 
				{
					emit(symtable[$2].name+string(":"),-1,-1,-1,0);
					localcontext++;
					context++;
					$1 = addfunctotable($2,localcontext,-1);
					functionaloffset = 8;
				}
		arguments';' 
				{
					if($3 != -1)
					{
						vector<int> ar;
						vector<int>::iterator ids;
						for(ids = help.begin(); ids != help.end(); ids++)
						{
							ar.push_back(*ids);
						}
						symtable[$1].function_args =ar;
						help.clear();
					}
				}
	;
arguments:
	'(' parameter_list')'	{$$ = 1;}
	| %empty	{$$ = -1;}
	;
parameter_list:
	identifier_list':' type				
									  {
										vector<int>::iterator ids;
										ValueType v;
										if($3 <= REA || $3<= INT)
										{
											if($3 == INT)
											{
												v = INT;
											}
											else 
												v = REA;
											for(ids = help.end() - 1; ids >= help.begin();ids--)
											{
												modifyreference(*ids, v,functionaloffset,localcontext,-1);
											}
											help.clear();
										}
										else
										{
											
											$3 = $3-REA-INT;
											v = symtable[$3].vtype;
											for(ids = help.end() - 1; ids >= help.begin();ids--)
											{
												modifyreference(*ids, v,functionaloffset,localcontext,$3);
											}
											help.clear();
										}
									}
	| parameter_list';' identifier_list':' type 
									  {
										vector<int>::iterator ids;
										ValueType v;
										if($5 <= REA || $5<= INT)
										{
											if($5 == INT)
											{
												v = INT;
											}
											else 
												v = REA;
											
											for(ids = help.end() - 1; ids >= help.begin();ids--)
											{
												modifyreference(*ids, v,functionaloffset,localcontext,-1 );
											}
											help.clear();
										}
										else
										{
											
											$5 = $5-REA-INT;
											v = symtable[$5].vtype;
											for(ids = help.end() - 1; ids >= help.begin();ids--)
											{
												modifyreference(*ids, v,functionaloffset,localcontext,$5);
											}
										}
											help.clear();
									}
	;
compound_statement:
    BEGIN_T optional_statements END_T 
    ;
optional_statements:
	statement_list
	| %empty
	;
statement_list:
    statement 		
    | statement_list ';' statement  
    ;

statement:
    assignment_statement 
    | procedure_statement
    | compound_statement
    | IF expression
		{
			int then = addlabel();
			int false_number = addtotable("0", symtable[$2].vtype);
			emit(string("je.i"),$2,false_number,then,3);
			$$ = then;
		}
     THEN statement 
		{
			int elsel = addlabel();
			emit(string("jump.i"), -1,-1,elsel,1);
			emit(symtable[$3].name+string(":"),-1,-1,-1,0);
			$4 = elsel;
		}
     ELSE statement
		{
			emit(symtable[$4].name+string(":"),-1,-1,-1,0);
			
		}
    | WHILE 
		{
            int loop = addlabel();
            int secondloop = addlabel();
            emit(symtable[secondloop].name+string(":"),-1,-1,-1,0);
            $$ = loop;
            $1 = secondloop;
		}   
		expression DO
		{
			int false_number = addtotable("0", symtable[$2].vtype);
			emit(string("je.i"),$3,false_number,$2,3);
		}
		statement
		{
			emit(string("jump.i"), -1,-1,$1,1);
			emit(symtable[$2].name+string(":"),-1,-1,-1,0);
		}
    ;

assignment_statement:
    variable ASSIGNOP expression 	{
								int position = convert_to_assignment($1,$3);
								if(position == -1)
								{
									gencode($2,$3,$1,symtable[$1].name);
								}
								else
									gencode($2,position,$1,symtable[$1].name);
							}
    ;
variable:
	ID		{   
				if(symtable[$1].type == FUNC && ((symtable[$1].context != localcontext)||context == 1))
				{
					int t = add_temptotable(symtable[$1].vtype);
					emit(string("push.i"),-1,-1,t,1);
					emit(string("call.i"),-1,-1,$1,1);
					emit(string("incsp.i"),-1,-1,addtotable(to_string(4), INT),1);
					$$ = t;
				}
				else
					$$ = $1;
			}
	| ID '[' expression']'	
							{
								if(symtable[$3].vtype == REA) {
								int t = add_temptotable(INT);
								emit(string("realtoint.r"), $3, -1, t, 2);
								$3 = t;
								}
								int val = addtotable(to_string(symtable[$1].arr.start), symtable[$1].vtype);
								int t2 = add_temptotable(INT);
								emit(string("sub.i"),$3,val,t2,3);
								if(symtable[$1].vtype == REA)
									val = addtotable(to_string(8), REA);
								else
									val = addtotable(to_string(4),INT);
								emit(string("mul.i"),t2,val,t2,3);
								int ref = -1;
								if(context == 1)
								{
									ref = add_referencetotable(symtable[$1].vtype,context,4);
								}
								else
								{
									negoffset -=4;
									ref = add_referencetotable(symtable[$1].vtype,localcontext,negoffset);									
								}
								val = addtotable(to_string(symtable[$1].offset),INT);
								addressReference = true;
								emit(string("add.i"),$1,t2,ref,3);
								$$ = ref;
							}
	;
procedure_statement:
	READOP'('expression_list')'	{
								vector<int>::iterator ids;
								for(ids = help_exp.begin(); ids != help_exp.end();ids++)
								{
									emit(string("read")+determine_type(*ids),-1,-1,*ids,1);
								}
								help_exp.clear();
							}
	| WRITEOP'('expression_list')'	{
										vector<int>::iterator ids;
										for(ids = help_exp.begin(); ids != help_exp.end();ids++)
										{
											emit(string("write")+determine_type(*ids),-1,-1,*ids,1);
										}
										help_exp.clear();
									}
	| ID	{
					emit("call.i",-1,-1,$1,1);				
			}
	| ID '(' expression_list ')' 
			{
				int incsp = 0;
				vector<int>::iterator ids;
				for(ids = help_exp.begin(); ids != help_exp.end(); ids++, incsp += 4) {
					emit("push.i",-1,-1,*ids,1);
				}
				help_exp.clear();
				emit("call.i",-1,-1,$1,1);
				int num = addtotable(to_string(incsp), INT);
				emit("incsp.i",-1,-1,num,1);
			}
	;
expression_list:
	expression	{help_exp.push_back($1);}
	| expression_list ',' expression{help_exp.push_back($3);}
	;
expression:
    simple_expression
    | simple_expression RELOP simple_expression{
													int position = add_temptotable(INT);
													int jump_label = addlabel();
													string command = string("");
													switch($2)
													{
														case EQ:
															command = string("je")+ determine_type($1);
															break;
														case NEQ:
															command = string("jne")+ determine_type($1);
															break;
														case LT:
															command = string("jl")+ determine_type($1);
															break;
														case LEQ:
															command = string("jle")+ determine_type($1);
															break;
														case GT:
															command = string("jg")+ determine_type($1);
															break;
														case GEQ:
															command = string("jge")+ determine_type($1);
															break;
													}
													emit(command, $1, $3, jump_label,3);
													int false_number = addtotable("0", INT);
													int end_jump = addlabel();
													gencode('=',false_number,-1,symtable[position].name);
													

													emit(string("jump.i"), -1,-1,end_jump,1);
													emit(symtable[jump_label].name+string(":"),-1,-1,-1,0);
													int true_number = addtotable("1", INT);
													gencode('=',true_number,-1,symtable[position].name);
													
													emit(symtable[end_jump].name+string(":"),-1,-1,-1,0);
													$$ = position;
												}
    ;	
simple_expression:
	term
	| ADDOP term
	| simple_expression ADDOP term {
										int  position = 0;
										int new_position = -1;
										position = convert_to_propertype($1,$3);
										if(position == -1)
										{
											position = add_temptotable(symtable[$1].vtype);
										}
										else
											new_position = add_temptotable(REA);
										if(new_position == -1)
										{
											$$ = position;
											gencode($2,$1,$3,symtable[position].name);
										}
										else
										{
											if(symtable[$1].vtype == INT)
												gencode($2,position,$3,symtable[new_position].name);
											else
												gencode($2,$1,position,symtable[new_position].name);
											$$ = new_position;
										}
								}
	| simple_expression OR term {
									int  position = 0;
									int new_position = -1;
									position = convert_to_propertype($1,$3);
									if(position == -1)
									{
										position = add_temptotable(symtable[$1].vtype);
									}
									else
										new_position = add_temptotable(REA);
									if(new_position == -1)
									{
										$$ = position;
										gencode($2,$1,$3,symtable[position].name);
									}
									else
									{
										if(symtable[$1].vtype == INT)
											gencode($2,position,$3,symtable[new_position].name);
										else
											gencode($2,$1,position,symtable[new_position].name);
										$$ = new_position;
									}
								}
	;
term:
    factor
    | term MULOP factor {
										int  position = 0;
										int new_position = -1;
										position = convert_to_propertype($1,$3);
										if(position == -1)
										{
											position = add_temptotable(symtable[$1].vtype);
										}
										else
											new_position = add_temptotable(REA);
										if(new_position == -1)
										{
											$$ = position;
											gencode($2,$1,$3,symtable[position].name);
										}
										else
										{
											if(symtable[$1].vtype == INT)
												gencode($2,position,$3,symtable[new_position].name);
											else
												gencode($2,$1,position,symtable[new_position].name);
											$$ = new_position;
										}
						}
    ;

factor:
    variable
 | ID '(' expression_list')'
			{
				if(symtable[$1].type == FUNC)
				{
					int incsp = 0;
					vector<int>::iterator ids;
					vector<int>::iterator ass;
					for(ass = help_exp.begin(); ass != help_exp.end(); ass++)
					{
						//cout << symtable[*ass].name <<"przed"<<endl;
					}
					int num_args = symtable[$1].function_args.size();
					ass = help_exp.end() - num_args;
					for(ids = symtable[$1].function_args.end() - 1; 
						ids >= symtable[$1].function_args.begin(); 
						ids--, ass++, incsp += 4) 
					{
						int position = *ass;

						if(symtable[*ass].type == NUM)
						{
							position = add_temptotable(symtable[*ids].vtype);
							if(symtable[*ass].vtype == REA && symtable[*ids].vtype == INT)
								symtable[*ass].name = to_string(stoi(symtable[*ass].name));
							emit(string("mov" + determine_type(*ids)), *ass, -1, position, 2);
						}
						if(symtable[*ass].type == IDENTIFIER)
						{
							int new_position = -1;
							if(symtable[*ass].vtype != symtable[*ids].vtype)
							{
								new_position = add_temptotable(symtable[*ids].vtype);
								if(symtable[*ass].vtype == INT)
								{   
									emit("inttoreal.i", *ass, -1, new_position, 2);
								}
								else
								{
									emit("realtoint.r", *ass, -1, new_position, 2);
								}
							}    

							if(new_position != -1)
								position = new_position;
						}
						emit("push.i", -1, -1, position, 1);
					}
					help_exp.erase(help_exp.end() - num_args, help_exp.end());
					for(ass = help_exp.begin(); ass != help_exp.end(); ass++)
					{
						//cout << symtable[*ass].name <<" po "<<endl;
					}
					int result = add_temptotable(symtable[$1].vtype);
					emit("push.i", -1, -1, result, 1);
					incsp += 4;
					$$ = result;
					emit(string("call.i"), -1, -1, $1, 1);
					emit(string("incsp.i"), -1, -1, addtotable(to_string(incsp), INT), 1);
				}
			}

    | NUMBER
		{          
			$$ = $1; 
		}
    | '(' expression ')'
		{
			$$ = $2;
		}
	| NOT factor	{
						if (symtable[$2].vtype == REA)
						{
							int temp = add_temptotable(INT);
							emit(string("realtoint.r"), $2, -1, temp, 2);
							$2 = temp;8
						}
						int jump_label = addlabel();
						int false_number = addtotable("0", INT);
						emit(string("je.i"),$2,false_number,jump_label,3);
						int sjump_label = addlabel();
						int temp_neg = add_temptotable(INT);
						gencode('=',false_number,-1,symtable[temp_neg].name);
						emit(string("jump.i"), -1,-1,sjump_label,1);
						
						emit(symtable[jump_label].name+string(":"),-1,-1,-1,0);
						int true_number = addtotable("1", INT);
						gencode('=',true_number,-1,symtable[temp_neg].name);
						
						emit(symtable[sjump_label].name+string(":"),-1,-1,-1,0);
						$$ = temp_neg;
						
					}
    ;
%%
void gencode(char op, int arg1, int arg2, string tname)
{

	switch(op)
	{
		case 'o':
			emit(string("or")+determine_type(arg1),arg1 , arg2 , lookup(tname) ,3); 
			break;
		case 'a':
			emit(string("and")+determine_type(arg1),arg1 , arg2 , lookup(tname) ,3); 
			break;			
		case '+':
			//cout << newtemp.name;
			emit(string("add")+determine_type(arg1),arg1 , arg2 , lookup(tname) ,3); 
			break;
		case '-':
			emit(string("sub")+determine_type(arg1),arg1 , arg2 , lookup(tname) ,3); 
			break;
		case '*':
			emit(string("mul")+determine_type(arg1),arg1 , arg2 , lookup(tname) ,3); 
			break;
		case '/':
			emit(string("div")+determine_type(arg1),arg1 , arg2 , lookup(tname) ,3);
			break; 
		case '=':
			emit(string("mov")+determine_type(arg1),arg1,-1,lookup(tname) ,2);
			break;
		case '%':
			emit(string("mod")+determine_type(arg1),arg1 , arg2 , lookup(tname) ,3); 
			break;
		default:
			return;
	}
}
int add_referencetotable(ValueType vtype, int cont,int offs)
{
	return addreferancetotable(vtype, cont,offs);
}
int addlabel()
{
	return addlabeltotable();
}
int add_temptotable(ValueType vtype)
{
	std::ostringstream oss;
	oss << "t" << tempno; 
	string temp = oss.str();
	int position = -1;
	if(context == 1)
		position = addtotable(temp,vtype,IDENTIFIER);
	else
	{
		if(vtype == REA)
			negoffset -=8;
		else
			negoffset -=4;
		position = addtotable(temp,vtype,IDENTIFIER,localcontext,negoffset);
	}
	tempno++;
	return position;
}
int convert_to_propertype(int arg1,int arg2)
{
	int position = -1;
	if((symtable[arg1].vtype == INT && symtable[arg2].vtype == INT)||(symtable[arg1].vtype == REA && symtable[arg2].vtype == REA))
	{
		return position;
	}
	else
	{
		position = add_temptotable(REA);
		if(symtable[arg1].vtype == INT && symtable[arg2].vtype == REA)
			emit(string("inttoreal.i"), arg1, -1, position, 2);
		else
			emit(string("inttoreal.i"), arg2, -1, position, 2);
	}
	return position;
}
int convert_to_assignment(int lside, int assignment)
{
	if(symtable[lside].vtype == symtable[assignment].vtype)
		return -1;
	if(symtable[lside].vtype == INT)
	{
		int position = add_temptotable(INT);
		emit(string("realtoint.r"), assignment, -1, position, 2);
		return position;
	}
	else
	{
		int position = add_temptotable(REA);
		emit(string("inttoreal.i"), assignment, -1, position, 2);
		return position;
	}
}
string determine_type(int arg1)
{
	if(symtable[arg1].vtype == INT)
		return string(".i ");
	else
		return string(".r ");
}
void emit(string command, int arg1, int arg2, int output, int arg_count)
{
    string instruction;

    if (arg_count == 0)
    {
        instruction = command + "\n";
        if(context == 1)
			cout << instruction;
        else
            function_body.push_back(instruction);
        return;
    }
    SymbolType type = symtable[output].type;
    int offset = symtable[output].offset;
	
    if (arg_count == 1)
    {
        if (symtable[output].type == NUM || symtable[output].type == LABEL || symtable[output].type == FUNC)
            instruction = command + "  #" + symtable[output].name + "\n";
        else
        {
            instruction = command + " " + determine_offset(output,command) + "\n";
        }
        if(context == 1)
			cout << "\t"+instruction;
        else 
            function_body.push_back(instruction);

        return;
    }

    instruction = command + " ";

    if (symtable[arg1].type == NUM || symtable[arg1].type == LABEL)
        instruction += "#" + symtable[arg1].name;
    else
        instruction += determine_offset(arg1,command);

    instruction += ", ";

    if (arg_count == 2)
    {
        if (type == LABEL)
            instruction += "#"+ symtable[output].name + "\n";
        else
            instruction += determine_offset(output,command)  + "\n";
        if(context == 1)
			cout << "\t"+instruction;
        else
            function_body.push_back(instruction);
        return;
    }

    if (arg_count == 3)
    {
        if (symtable[arg2].type == NUM || symtable[arg2].type == LABEL)
            instruction += "#" + symtable[arg2].name;
        else
            instruction += determine_offset(arg2,command); 

        if (type == LABEL || type == FUNC)
            instruction += ", #" + symtable[output].name + "\n";
        else
            instruction += ", " + determine_offset(output,command)  + "\n";
		if(context == 1)
			cout<<"\t"+instruction;
		else	
            function_body.push_back(instruction);

        return;
    }
}
string determine_offset(int ind,string command )
{
	if(symtable[ind].context == 1)
	{	
		if(command.find("push") != string::npos && symtable[ind].type != REFERENCE)
			return string("#"+to_string(symtable[ind].offset));
		if(command.find("push") != string::npos && symtable[ind].type == REFERENCE)
			return string(to_string(symtable[ind].offset));
		if(symtable[ind].type == REFERENCE && addressReference == true)
		{
			addressReference = false;
			return string(to_string(symtable[ind].offset));
		}
		else if(symtable[ind].type == REFERENCE)
		{
			return string("*"+to_string(symtable[ind].offset));
		}
		else
			return to_string(symtable[ind].offset);
	}
	else
	{
		if(symtable[ind].offset > 0)
		{
			if(symtable[ind].type == REFERENCE)
			{
				if(command.find("push") != string::npos && symtable[ind].type == REFERENCE)
					return string("BP+")+to_string(symtable[ind].offset);
				if(addressReference == true)
				{
					addressReference = false;
					return string("BP+")+to_string(symtable[ind].offset);
				}
				else
					return string("*BP+")+to_string(symtable[ind].offset);
			}
			if(symtable[ind].type == FUNC )
				return string("*BP+")+to_string(symtable[ind].offset);
			else if(symtable[ind].type == IDENTIFIER && addressReference == false)
			{
				return string("BP+")+to_string(symtable[ind].offset);
			}
			else
				return string("*BP+")+to_string(symtable[ind].offset);
		}
		else
		{	
			if(command.find("push") != string::npos && symtable[ind].type == REFERENCE)
				return string("BP")+to_string(symtable[ind].offset);
			else if(command.find("push") != string::npos && symtable[ind].type != REFERENCE)
				return string("#BP")+to_string(symtable[ind].offset);
			if(symtable[ind].type == REFERENCE && addressReference == true)
			{
				addressReference = false;
				return string("BP")+to_string(symtable[ind].offset);
			}
			else if(symtable[ind].type == REFERENCE)
			{
				return string("*BP")+to_string(symtable[ind].offset);				
			}
			else 
				return string("BP")+to_string(symtable[ind].offset); 
		}
	}
}
void printAndClearFunctionBody() {
	string enterInstruction = "enter.i #" + to_string(count_enter(localcontext)) + "\n";
	function_body.insert(function_body.begin(), enterInstruction);
	function_body.push_back(string("leave\n"));
	function_body.push_back(string("return\n"));
    for (const string &instr : function_body) {
		if(instr.find(":") != string::npos)
			cout << instr;
        else
			cout << string("\t")+instr;
    }
    function_body.clear();
}

void yyerror(const char *s) {
    extern char *yytext;   
    cerr << "Błąd składni: " << s << " w linii " << lineno << " przy tokenie: " << yytext << endl;
}

