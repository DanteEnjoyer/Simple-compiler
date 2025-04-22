#include <string>
#include <vector>
#include <iostream>
#include <sstream>
int yylex_destroy();

using namespace std;

enum SymbolType{
	IDENTIFIER,
	NUM,
	LABEL,
	ARRAYTYPE,
	REFERENCE,
	FUNC
};
enum ValueType{
	INT,
	REA
};
struct ArrayInfo{
	int start;
	int end;
	int size;
};
struct entry_t{
  string name;	
  int offset;
  enum SymbolType type;
  enum ValueType vtype;
  vector<int> function_args;
  struct ArrayInfo arr = {-1, -1, -1}; 
  int context = 1;
  
};
typedef vector<entry_t> symtable_t;

extern symtable_t symtable;
extern int lineno;
extern int context;
extern int localcontext;
extern int negoffset;

int addtotable(struct entry_t &s);
int addtotable(string id);
int addtotable(string number, ValueType type);
int addtotable(string number, ValueType type, SymbolType iden);
int addtotable(string number, ValueType type, SymbolType iden, int cont, int offs);
int addlabeltotable();
int addreferancetotable(ValueType vtype,int cont,int offs);
int addfunctotable(int ind,int cont,int offs);
int addnonetotable(int low, int high, ValueType type);
void modifyarray(int ind, ValueType type, int size, int copy_index);
void modifyarray(int ind, ValueType type, int size, int copy_index, int offs,int localcont);
void modifyidentifier(int ind, ValueType type);
void modifyidentifier(int ind, ValueType type, int offs, int localcontext);
void modifyreference(int ind, ValueType type,int offs,int con,int copy_array);
void modifyreference(int ind,int offs);
void modifylabel(int ind, int cont);
int count_enter(int con);
int lookup(const string& s);
int lookup(const string& s, int cont);
void print_symtable(symtable_t s);
string symbolTypeToString(SymbolType type);
string ValueTypeToString(ValueType type);
string IntToContext(int cont);
void incrementoffset(int size);
void init_symtable();
void config_labels(struct entry_t &s, string name);
void emit_begend(int mode);
