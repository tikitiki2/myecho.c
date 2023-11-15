myecho:myecho.o helpers.o
	gcc myecho.o helpers.o -o myecho -lm
myecho.o:myecho.c
	gcc -c myecho.c
helpers.o:helpers.c
	gcc -c helpers.c -lm
