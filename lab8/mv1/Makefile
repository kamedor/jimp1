a.out: main.o parser.o alex.o 
	$(CC) $(CFLAGS) main.o parser.o alex.o

main.o:	main.c parser.h alex.h fun_stack.h

parser.o: parser.c parser.h alex.h fun_stack.h

alex.o: alex.c alex.h fun_stack.h

clean:
	-rm a.out
	-rm *.o
	-rm *~
