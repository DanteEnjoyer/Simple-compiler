test: parsertab.o lexer.o symtable.o main.o
	g++ -std=c++20 -o test parsertab.o lexer.o symtable.o main.o

main.o: main.cpp symtable.h
	g++ -std=c++20 -c main.cpp

symtable.o: symtable.cpp symtable.h
	g++ -std=c++20 -c symtable.cpp

parsertab.o: parsertab.cpp symtable.h
	g++ -std=c++20 -c parsertab.cpp

lexer.o: lexer.cpp parsertab.hpp
	g++ -std=c++20 -c lexer.cpp

parsertab.hpp parsertab.cpp: parser.y
	bison --defines=parsertab.hpp -o parsertab.cpp parser.y

lexer.cpp: lexer.l 
	flex -o lexer.cpp lexer.l

clean:
	rm -f lexer.o parsertab.o main.o symtable.o lexer.cpp parsertab.cpp parsertab.hpp test
