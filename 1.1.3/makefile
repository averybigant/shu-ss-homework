03.out 03db.out : main.o SeqList.o
	gcc -Wall -o 03.out main.o SeqList.o
	gcc -Wall -g -o 03db.out maindb.o SeqListdb.o
main.o maindb.o : 11121281_03.c SeqList.h
	gcc -Wall -c -o main.o 11121281_03.c
	gcc -Wall -g -c -o maindb.o 11121281_03.c
SeqList.o SeqListdb.o : SeqList.c SeqList.h
	gcc -Wall -c -o SeqList.o SeqList.c
	gcc -Wall -g -c -o SeqListdb.o SeqList.c
clean :
	rm *.o
