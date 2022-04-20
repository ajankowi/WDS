
CPPFLAGS=-Wall -pedantic -Iinc
LFLAGS=-Wall

__start__: nadawanie odbieranie
	@echo
	@echo "   Utworzone zostaly programy: nadawanie, odbieranie"
	@echo


obj/transparam.o: inc/transparam.hh src/transparam.cpp
	g++ ${CPPFLAGS} -c -o obj/transparam.o src/transparam.cpp

obj/nadawanie.o: inc/transparam.hh src/nadawanie.cpp
	g++ ${CPPFLAGS} -c -o obj/nadawanie.o src/nadawanie.cpp

obj/odbieranie.o: inc/transparam.hh src/odbieranie.cpp
	g++ ${CPPFLAGS} -c -o obj/odbieranie.o src/odbieranie.cpp

nadawanie: obj/transparam.o obj/nadawanie.o
	g++ ${LFLAGS} -o nadawanie obj/transparam.o obj/nadawanie.o -lrt

odbieranie: obj/transparam.o obj/odbieranie.o
	g++ ${LFLAGS} -o odbieranie obj/transparam.o obj/odbieranie.o -lrt

clean:
	rm -f odbieranie nadawanie obj/*
