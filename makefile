all: main.o album.o id3reader.o library.o
	gcc -o test main.o album.o id3reader.o library.o -lavformat -lavutil -lavcodec

main.o: main.c album.h id3reader.h library.h
		gcc -c main.c

album.o: album.c album.h id3reader.h
	gcc -c album.c

id3reader.o: id3reader.c id3reader.h
	gcc -c id3reader.c

library.o: library.c library.h album.h id3reader.h
	gcc -c library.c

clean:
	-rm *.o
	-rm *~
	-rm *.exe
	-rm test
