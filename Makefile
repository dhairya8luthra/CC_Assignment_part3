proj3: proj3.tab.c lex.yy.c
	gcc -o proj3 proj3.tab.c lex.yy.c symbol_table.c -lfl

proj3.tab.c proj3.tab.h: proj3.y
	bison -d proj3.y

lex.yy.c: proj3.l proj3.tab.h
	flex proj3.l

clean:
	rm -f proj3 proj3.tab.c proj3.tab.h lex.yy.c