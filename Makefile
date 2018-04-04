#this build system is deprecated and we have shifted to CMAKE 

all:
	$(MAKE) grammer
	$(MAKE)	lex
	g++ -c -std=gnu++11 compiler/grammer.tab.c compiler/lex.yy.c -Wwrite-strings
	mv *.o compiler
	ar rvs compiler/lexgram.a compiler/grammer.tab.o compiler/lex.yy.o
	g++ -std=gnu++11 -o bin/freamps  -Wall -Wextra compiler/main.cc compiler/lexgram.a
grammer:
	bison -d compiler/grammer.y
	mv grammer.tab.* compiler
lex:
	flex compiler/lex.l
	mv lex.yy.c compiler
run:
	${MAKE} all
	${MAKE} check
check:
	./bin/freamps < test/enter.code
	./bin/freamps < test/enterName.code
clean:
	rm compiler/grammer.tab.* compiler/lex.yy.* compiler/lexgram.a bin/*

