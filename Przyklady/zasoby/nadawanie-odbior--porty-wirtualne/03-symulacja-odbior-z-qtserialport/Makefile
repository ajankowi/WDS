NAZWA_APLIKACJI=odbiornik-qt
URUCHOMIENIE_APLIKACJI=./${NAZWA_APLIKACJI}
ZRODLA_PROJEKTU=`/bin/pwd`/src/*.cpp\
                `/bin/pwd`/inc/*.hh
PODSTAWIENIA=OBJECTS_DIR=${KATALOG_OBJ}\
             INCLUDEPATH=inc\
             INCLUDEPATH+=inc/rs232\
             MOC_DIR=./out/moc\
             QT+=widgets\
             QT+=serialport\
             QMAKE_CXXFLAGS+=-std=c++17

KATALOG_OBJ=./obj

CPPFLAGS=-Wall -pedantic -Iinc -Iinc/rs232
LFLAGS=-Wall

__start__: __empty_lines__ __sprawdz_Qt__ ${NAZWA_APLIKACJI}
	#rm -f core*; ${URUCHOMIENIE_APLIKACJI}
	@echo
	@echo " Utworzono aplikacje:  odbiornik-qt (nasluchuje na porcie podanym jako parametr wywolania)"
	@echo "                       nadawanie    (transmituje do portu podanego jako parametr wywolania)"
	@echo

__empty_lines__:
	@printf "\n\n\n\n"


__sprawdz_Qt__: __sprawdz_qmake__
	@if qmake -v | grep 'ver.*5\.[0-9]*\.[0-9]*' > /dev/null;\
         then exit 0;\
         else echo; echo " Brak biblioteki Qt w wersji 4.x.x";\
              echo;  exit 1;\
        fi

__sprawdz_qmake__:
	@if which qmake > /dev/null; then exit 0;\
        else\
          echo; echo " Brak programu qmake."\
               " Prawdopodobnie biblioteka Qt nie zostala zainstalowana.";\
          echo; exit 1;\
        fi


${NAZWA_APLIKACJI}: Makefile.app  __sprawdz__  __nadajnik__

__nadajnik__:  obj/transparam.o obj/nadawanie.o
	g++ ${LFLAGS} -o nadawanie obj/transparam.o obj/nadawanie.o -lrt

obj/nadawanie.o: inc/rs232/transparam.hh src-nadajnik/nadawanie.cpp
	g++ ${CPPFLAGS} -c -o obj/nadawanie.o src-nadajnik/nadawanie.cpp

obj/transparam.o: inc/rs232/transparam.hh src-nadajnik/rs232/transparam.cpp
	g++ ${CPPFLAGS} -c -o obj/transparam.o src-nadajnik/rs232/transparam.cpp

__sprawdz__:
	make -f Makefile.app

Makefile.app: out/pro/${NAZWA_APLIKACJI}.pro
	qmake -o Makefile.app out/pro/${NAZWA_APLIKACJI}.pro

out/pro/${NAZWA_APLIKACJI}.pro: Makefile
	rm -fr out/pro/
	qmake -project -nopwd -o out/pro/${NAZWA_APLIKACJI}.pro\
               ${PODSTAWIENIA} ${ZRODLA_PROJEKTU} 

project: __usun_pro__ out/pro/${NAZWA_APLIKACJI}.pro

__usun_pro__:
	rm -f out/pro/${NAZWA_APLIKACJI}.pro

clean:
	rm -f nadawanie
	make -f Makefile.app clean


cleanall: clean
	rm -f ${NAZWA_APLIKACJI}

__clean_auxiliary_files__:
	find . -name \*~ -exec rm {} \;
	find . -name \*.tex -exec rm {} \;

cleantotally: __clean_auxiliary_files__ cleanall
	rm -f  Makefile.app
	rm -fr out


help:
	@echo "Podcele:"
	@echo 
	@echo " project  - wymusza utworzenie nowego projektu"
	@echo " clean    - usuwa wszystkie produkty kompilacji i konsolidacji"
	@echo " cleanall - usuwa produkty kompilacji wraz z aplikacja"
	@echo " cleantotally - usuwa wszystko oprocz zrodel i pliku Makefile"
	@echo " help     - wyswietla niniejszy pomoc"
	@echo
