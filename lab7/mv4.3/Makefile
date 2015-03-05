CFLAGS = -ggdb

a.out: indx5.o vect.o skorowidz.o plik.o wyszukaj.o
	$(CC) $(CFLAGS) indx5.o vect.o skorowidz.o plik.o wyszukaj.o

indx5.o: indx5.c vect.h skorowidz.h plik.h wyszukaj.h

wyszukaj.o: wyszukaj.c skorowidz.h wyszukaj.h

skorowidz.o: skorowidz.c vect.h skorowidz.h

vect.o: vect.c vect.h

plik.o: plik.c plik.h

clean:
	-rm a.out
	-rm *.o
	-rm *~
