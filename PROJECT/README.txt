Group Members:
Ritvik 2020A7PS1723H
Abhinav Tyagi 2020A7PS2043H
Darshan Chandak 2020A7PS2085H
Jai Sehgal 2020A7PS2089H
Uday Singh Thakur 2020A7PS2050H

Run the program:
Place the code in "code.txt" file in each folder.

1. Lexical Analysis
lex LexicalAnalyzer.l
gcc lex.yy.c
./a.out

2. Syntax Analysis
yacc -d SyntaxAnalyzer.y && lex LexicalAnalyzer.l
gcc lex.yy.c y.tab.c -ll -ly
./a.out

3. Semantic Analysis
yacc -d SemanticAnalyzer.y && lex LexicalAnalyzer.l
gcc lex.yy.c y.tab.c -ll -ly
./a.out

4. Code Generation
yacc -d CodeGeneration.y && lex LexicalAnalyzer.l
gcc lex.yy.c y.tab.c -ll -ly
./a.out

5. Final Output
yacc -d SemanticAnalyzer.y && lex LexicalAnalyzer.l
gcc lex.yy.c y.tab.c -ll -ly
./a.out