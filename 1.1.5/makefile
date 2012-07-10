a.out adb.out : main.o linklist.o
	gcc -Wall -lm main.o linklist.o
	gcc -Wall -g -o adb.out -lm maindb.o linklistdb.o
main.o maindb.o: linklist.h 11121281_5.c
	gcc -Wall -c -o main.o 11121281_5.c -lm
	gcc -g -Wall -c -o maindb.o 11121281_5.c -lm
linklist.o linklistdb.o: linklist.h linklist.c
	gcc -Wall -c -o linklist.o linklist.c -lm
	gcc -g -Wall -c -o linklistdb.o linklist.c -lm
clean:
	rm *.o
