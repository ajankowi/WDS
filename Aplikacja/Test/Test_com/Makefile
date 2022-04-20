#
#  To sa opcje dla kompilacji
#
CPPFLAGS=-Wall -pedantic -Iinc
LFLAGS=-Wall


TRGDIR=/tmp/rs232

__start__: ./rs232
	./rs232

./rs232: obj obj/main.o obj/transparam.o obj/nadawanie.o obj/odbieranie.o 

	g++ ${LFLAGS} -o ./rs232 obj/main.o\
                         obj/transparam.o obj/nadawanie.o obj/odbieranie.o


obj:
	mkdir -p obj

obj/main.o: src/main.cpp inc/nadawanie.hh inc/odbieranie.hh inc/transparam.hh     
	g++ -c ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/transparam.o: inc/transparam.hh src/transparam.cpp
	g++ -c ${CPPFLAGS} -o obj/transparam.o src/transparam.cpp

obj/nadawanie.o: src/nadawanie.cpp inc/nadawanie.hh 
	g++ -c ${CPPFLAGS} -o obj/nadawanie.o src/nadawanie.cpp

obj/odbieranie.o: src/odbieranie.cpp inc/odbieranie.hh 
	g++ -c ${CPPFLAGS} -o obj/odbieranie.o src/odbieranie.cpp




clean:
	rm -f obj/*.o ./rs232