a.out: main.o parser.o alex.o fun_stack.o 
	$(CC) $(CFLAGS) main.o parser.o alex.o fun_stack.o

main.o:	main.c parser.h alex.h fun_stack.h

parser.o: parser.c parser.h alex.h fun_stack.h

alex.o: alex.c alex.h fun_stack.h

fun_stack.o: fun_stack.c fun_stack.h

clean:
	-rm a.out
	-rm *.o
	-rm *~
