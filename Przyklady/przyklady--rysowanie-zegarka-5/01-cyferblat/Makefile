NAZWA_APLIKACJI=cyferblat1
URUCHOMIENIE_APLIKACJI=./cyferblat1
ZRODLA_PROJEKTU=`/bin/pwd`/src/*.cpp `/bin/pwd`/inc/*.hh
PODSTAWIENIA=OBJECTS_DIR=${KATALOG_OBJ} INCLUDEPATH=inc\
             MOC_DIR=${KATALOG_MOC} QT+=widgets
KATALOG_OBJ=./out/obj
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

__clean_auxiliary_files__:
	find . -name \*~ -exec rm {} \;
	find . -name \*.tex -exec rm {} \;

cleantotally: __clean_auxiliary_files__ cleanall
	rm -f  Makefile.app
	rm -fr ${KATALOG_MOC} ${KATALOG_OBJ}
	rm -rf out/

help:
	@echo "Podcele:"
	@echo 
	@echo " project  - wymusza utworzenie nowego projektu"
	@echo " clean    - usuwa wszystkie produkty kompilacji i konsolidacji"
	@echo " cleanall - usuwa produkty kompilacji wraz z aplikacja"
	@echo " cleantotally - usuwa wszystko oprocz zrodel i pliku Makefile"
	@echo " help     - wyswietla niniejszy pomoc"
	@echo
