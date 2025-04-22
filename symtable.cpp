#include "symtable.h"
int offset = -12;
int labelcount = 1;
symtable_t symtable;

int addtotable(struct entry_t &s)
{
	for (int i = 0; i < symtable.size(); i++) {
        if(symtable[i].name == s.name)
			return i;
    }
    if(s.type == IDENTIFIER || s.type == LABEL)
    {
		cout << s.name<< endl;
		s.offset = offset;
		if(s.vtype == INT || s.type == LABEL)
			offset +=4;
		else
			offset +=8;
	}
	else 
		s.offset = -1;
	symtable.push_back(s);
    return symtable.size()-1;
}
int addtotable(string number, ValueType type)
{
		for (int i = 0; i < symtable.size(); i++) {
        if(symtable[i].name == number)
			return i;
		}
		struct entry_t n;
		n.name = number;
		n.type = NUM;
		n.offset = -1;
		n.vtype = type;
		symtable.push_back(n);
		return symtable.size()-1;
}
int addtotable(string id)
{
		struct entry_t n;
		n.name = id;
		n.type = IDENTIFIER;
		if(context == 1)
			n.context = context;
		else
			n.context = localcontext;
		symtable.push_back(n);
		return symtable.size()-1;
}
int addtotable(string id, ValueType type, SymbolType iden)
{
		struct entry_t n;
		n.name = id;
		n.type = IDENTIFIER;
		n.vtype = type;
		n.offset = offset;
		if(type == REA)
			offset += 8;
		else
			offset +=4;
		symtable.push_back(n);
		return symtable.size()-1;
}
int addtotable(string id, ValueType type, SymbolType iden, int cont, int offs)
{
		struct entry_t n;
		n.name = id;
		n.type = IDENTIFIER;
		n.vtype = type;
		n.offset = offs;
		n.context = cont;
		symtable.push_back(n);
		return symtable.size()-1;	
}

int addlabeltotable()
{
	std::ostringstream oss;
	oss << "lab" << labelcount;
	labelcount++; 
	string temp = oss.str();
	struct entry_t n;
	n.name = temp;
	n.type = LABEL;
	n.offset = -1;
	symtable.push_back(n);
	return symtable.size()-1;	
}
int addnonetotable(int low, int high, ValueType type)
{
	struct entry_t n;
	n.type = ARRAYTYPE;
	n.arr.start = low;
	n.arr.end = high;
	n.arr.size = high - low  + 1;
	n.vtype = type;
	n.offset = -1;
	symtable.push_back(n);
	return symtable.size()-1;
}
int addreferancetotable(ValueType vtype,int cont, int offs)
{
	struct entry_t n;
	n.context = cont;
	if(cont == 1)
	{
		n.offset = offset;
		offset +=4;
	}
	else
	{
		n.offset = offs;
	}
	n.name = to_string(n.offset);
	n.type = REFERENCE;
	n.vtype = vtype;
	symtable.push_back(n);
	return symtable.size()-1;
}

int addfunctotable(int ind,int cont,int offs)
{
	symtable[ind].context = cont;
	symtable[ind].type = FUNC;
	symtable[ind].offset = offs;
	return symtable.size()-1;
}
void modifylabel(int ind, int cont)
{
	symtable[ind].type = LABEL;
	symtable[ind].context = cont;
}
void modifyidentifier(int ind, ValueType type)
{
		symtable[ind].vtype = type;
		symtable[ind].offset = offset;
		if(type == REA)
			offset += 8;
		else
			offset +=4;
}
void modifyidentifier(int ind, ValueType type, int offs,int localcont)
{
		symtable[ind].vtype = type;
		symtable[ind].offset = offs;
		symtable[ind].context = localcont;
}
void modifyreference(int ind, ValueType type,int offs,int con,int copy_array)
{
	symtable[ind].type = REFERENCE;
	symtable[ind].vtype = type;
	symtable[ind].offset = offs;
	symtable[ind].context = con;
	if(copy_array != -1)
	{
		symtable[ind].arr.start = symtable[copy_array].arr.start;
		symtable[ind].arr.end = symtable[copy_array].arr.end;
		symtable[ind].arr.size = symtable[copy_array].arr.size;
	}
}
void modifyreference(int ind,int offs)
{
	symtable[ind].offset = offs;
}
int count_enter(int con)
{
		int size = 0;
		for (int i = 0; i < symtable.size(); i++) {	
			if(symtable[i].context == con && symtable[i].type==IDENTIFIER)
			{
				if(symtable[i].vtype == REA)
					size +=8;
				else
					size +=4;
			}
			if(symtable[i].context == con && symtable[i].type == REFERENCE && symtable[i].offset<0)
				size +=4;
			if(symtable[i].context == con && symtable[i].type==ARRAYTYPE)
				size += symtable[i].arr.size;
		}
		return size;
		
}
void modifyarray(int ind, ValueType type, int size, int copy_index)
{
	symtable[ind].vtype = type;
	symtable[ind].offset = offset;
	symtable[ind].type = ARRAYTYPE;
	symtable[ind].arr.start = symtable[copy_index].arr.start;
	symtable[ind].arr.end = symtable[copy_index].arr.end;
	symtable[ind].arr.size = size;
	if(type == REA)
		offset += 8*size;
	else
		offset += 4*size;
}
void modifyarray(int ind, ValueType type, int size, int copy_index, int offs, int localcont)
{
	symtable[ind].vtype = type;
	symtable[ind].offset = offs;
	symtable[ind].type = ARRAYTYPE;
	symtable[ind].context = localcont;
	symtable[ind].arr.start = symtable[copy_index].arr.start;
	symtable[ind].arr.end = symtable[copy_index].arr.end;
	symtable[ind].arr.size = size;
}
int lookup(const string& s)
{

	for (int i = 0; i < symtable.size(); i++) {
        if(symtable[i].name == s  && symtable[i].context == 1)
		{
				return i;
		}
		if(symtable[i].name == s && symtable[i].context !=1 && context == 1)
			return i;
    }
    return lookup(s,localcontext);
}
int lookup(const string& s, int cont)
{

	for (int i = 0; i < symtable.size(); i++) {
        if(symtable[i].name == s )
		{
			if(context != 1  && symtable[i].context==localcontext)
				return i;
			if(symtable[i].type == FUNC && symtable[i].context != localcontext)
				return i;
		}
    }
    return -1;
}
void print_symtable(symtable_t s)
{
	cout <<"\n\n\n";
	cout <<"Nazwa w tablicy "<<"Offset "<<"Typ "<<endl;
	for(int i = 0; i < symtable.size(); i++){
		if(1)
			cout << symtable[i].name <<" "<< symtable[i].offset <<" "<<symbolTypeToString(symtable[i].type)<<" "<< ValueTypeToString(symtable[i].vtype) << IntToContext(symtable[i].context)<<endl;
//		if(symtable[i].type == FUNC)
//			cout << symtable[i].function_args.size();
	}
}
string symbolTypeToString(SymbolType type) {
    switch (type) {
        case NUM:
            return "NUM";
        case IDENTIFIER:
            return "IDENTIFIER";
        case LABEL:
            return "LABEL";
        case ARRAYTYPE:
			return "ARRAY";
		case REFERENCE:
			return "REFERENCE";
		case FUNC:
			return "FUNCTION";
        default:
            return "UNKNOWN";
    }
}
string ValueTypeToString(ValueType type) {
    switch (type) {
        case INT:
            return "INTEGER";
        case REA:
            return "REAL";
        default:
            return "UNKNOWN";
    }
}
string IntToContext(int cont)
{
	switch(cont){
		case 1:
			return "GLOBAL";
		default:
			return "LOCAL";
	}
}
void incrementoffset(int size)
{
	offset += size;
}
void init_symtable()
{
	struct entry_t write;
	struct entry_t read;
	struct entry_t lab0;
	config_labels(write,"write");
	config_labels(read,"read");
	config_labels(lab0,"lab0");
}
void config_labels(struct entry_t &s, string name)
{
	s.type = LABEL;
	s.offset = -1;
	s.name = name;
	symtable.push_back(s);
}
void emit_begend(int mode)
{
	if(mode == 1)
	{
		cout << "jump.i     "<< "#lab0" << endl;
	}
	else
	{
		cout << "exit"<< endl;
	}
	
}
