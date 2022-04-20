NAZWA_APLIKACJI=rysowanie
URUCHOMIENIE_APLIKACJI=./rysowanie
ZRODLA_PROJEKTU=`/bin/pwd`/inc/*.hh `/bin/pwd`/src/*.cpp
PODSTAWIENIA=OBJECTS_DIR=${KATALOG_OBJ}\
             QT+=widgets\
             QMAKE_CXXFLAGS=-std=c++11\
             INCLUDEPATH+=inc\
             MOC_DIR=${KATALOG_MOC}

KATALOG_OBJ=./out/obj
KATALOG_PRO=./out/pro
KATALOG_MOC=./out/moc

__start__: __sprawdz_Qt__ ${NAZWA_APLIKACJI}
	rm -f core*; ${URUCHOMIENIE_APLIKACJI}

__sprawdz_Qt__: __sprawdz_qmake__
	@if qmake -v | grep 'ver.*5\.[0-9]*\.[0-9]*' > /dev/null;\
         then exit 0;\
         else echo; echo " Brak biblioteki Qt w wersji 5.x.x";\
              echo;  exit 1;\
        fi

__sprawdz_qmake__:
	@if which qmake > /dev/null; then exit 0;\
        else\
          echo; echo " Brak programu qmake."\
               " Prawdopodobnie biblioteka Qt nie zostala zainstalowana.";\
          echo; exit 1;\
        fi


${NAZWA_APLIKACJI}: Makefile.app __sprawdz__


${KATALOG_PRO}:
	mkdir -p ${KATALOG_PRO}

__sprawdz__:
	make -f Makefile.app

Makefile.app: ${KATALOG_PRO}/${NAZWA_APLIKACJI}.pro
	qmake -o Makefile.app ${KATALOG_PRO}/${NAZWA_APLIKACJI}.pro

${KATALOG_PRO}/${NAZWA_APLIKACJI}.pro: Makefile
	rm -f ${NAZWA_APLIKACJI}
	qmake -project -nopwd -o ${KATALOG_PRO}/${NAZWA_APLIKACJI}.pro\
               ${PODSTAWIENIA} ${ZRODLA_PROJEKTU} 

project: __usun_pro__ ${KATALOG_PRO}/${NAZWA_APLIKACJI}.pro

__usun_pro__:
	rm -f ${KATALOG_PRO}/${NAZWA_APLIKACJI}.pro

clean:
	make -f Makefile.app clean

cleanall: clean
	rm -f ${NAZWA_APLIKACJI}

cleantotally: cleanall
	rm -f  Makefile.app
	rm -fr ${KATALOG_OBJ} ${KATALOG_PRO} ${KATALOG_MOC}
	rm -fr out
	find . -name \*~ -exec rm {} \;
	find . -name \*.tex -exec rm {} \;

help:
	@echo "Podcele:"
	@echo 
	@echo " project  - wymusza utworzenie nowego projektu"
	@echo " clean    - usuwa wszystkie produkty kompilacji i konsolidacji"
	@echo " cleanall - usuwa produkty kompilacji wraz z aplikacja"
	@echo " cleantotally - usuwa wszystko oprocz zrodel i pliku Makefile"
	@echo " help     - wyswietla niniejszy pomoc"
	@echo
