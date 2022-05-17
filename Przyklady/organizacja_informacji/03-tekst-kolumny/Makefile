NAZWA_APLIKACJI=mapa3
URUCHOMIENIE_APLIKACJI=./${NAZWA_APLIKACJI}
ZRODLA_PROJEKTU=`/bin/pwd`/src/*.cpp `/bin/pwd`/inc/*.hh  `/bin/pwd`/ui/*.ui\
                `/bin/pwd`/res/*.qrc
PODSTAWIENIA=OBJECTS_DIR=${KATALOG_OBJ} INCLUDEPATH=inc\
                         MOC_DIR=out/moc\
                         UI_DIR=out/ui\
                         RCC_DIR=out/rcc\
                         QT+=widgets QMAKE_CXXFLAGS=-std=c++17
KATALOG_OBJ=./out/obj

__start__: __sprawdz_Qt__ __empty_lines__ ${NAZWA_APLIKACJI}
	rm -f core*; ${URUCHOMIENIE_APLIKACJI}

__empty_lines__:
	@printf "\n\n\n\n"

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


${NAZWA_APLIKACJI}: out/pro Makefile.app __sprawdz__


out/pro:
	mkdir -p out/pro

__sprawdz__:
	make -f Makefile.app

Makefile.app: out/pro/${NAZWA_APLIKACJI}.pro
	qmake -o Makefile.app out/pro/${NAZWA_APLIKACJI}.pro

out/pro/${NAZWA_APLIKACJI}.pro: Makefile
	rm -f ${NAZWA_APLIKACJI}
	qmake -project -nopwd -o out/pro/${NAZWA_APLIKACJI}.pro\
               ${PODSTAWIENIA} ${ZRODLA_PROJEKTU} 

project: __usun_pro__ out/pro/${NAZWA_APLIKACJI}.pro

__usun_pro__:
	rm -f out/pro/${NAZWA_APLIKACJI}.pro

clean:
	make -f Makefile.app clean

cleanall: clean
	rm -f ${NAZWA_APLIKACJI}

cleantotally: cleanall
	rm -f ${NAZWA_APLIKACJI}.pro Makefile.app
	rm -fr out/
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
