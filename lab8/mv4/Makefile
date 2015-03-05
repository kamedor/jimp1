test_alex: test_alex.o alex.o
	$(CC) test_alex.o alex.o -o test_alex

test_alex.o: test_alex.c alex.h

alex.o: alex.c alex.h


test_fun_stack: test_fun_stack.o fun_stack.o
	$(CC) test_fun_stack.o fun_stack.o -o test_fun_stack

test.o: test_fun_stack.c fun_stack.h

fun_stack.o: fun_stack.c fun_stack.h
	
clean:
	-rm test_alex
	-rm test_fun_stack
	-rm a.out
	-rm *~
	-rm *.o
