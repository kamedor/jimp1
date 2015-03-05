a.out: test.o fun_stack.o
	$(CC) test.o fun_stack.o

test.o: test.c fun_stack.h

fun_stack.o: fun_stack.c fun_stack.h

clean:
	-rm a.out
	-rm *~
	-rm *.o
