#+- SVN Keywords ----------------------------------------------------+
#|                                                                   |
#| $HeadURL: svn+ssh://bkreczmer@robrex.iiar.pwr.wroc.pl/home/bkreczmer/repos/GDiagUI/GDiagUI-software-qt4/trunk/Makefile $:
#|                                                                   |
#|    $Rev:: 8                                                     $:|
#|   $Date:: 2015-02-05 20:25:40 +0100 (Thu, 05 Feb 2015)          $:|
#| $Author:: bkreczmer                                             $:|
#|                                                                   |
#+-------------------------------------------------------------------+



NAZWA_APLIKACJI=menu-belka-dialog
URUCHOMIENIE_APLIKACJI=./menu-belka-dialog
ZRODLA_PROJEKTU=`/bin/pwd`/ui/*.ui `/bin/pwd`/res/*.qrc\
                `/bin/pwd`/src/*.cpp\
                `/bin/pwd`/inc/*.hh


KATALOG_OBJ=./out/obj
KATALOG_MOC=./out/moc

PODSTAWIENIA=OBJECTS_DIR=${KATALOG_OBJ} INCLUDEPATH=inc INCLUDEPATH+=ui/inc\
        INCLUDEPATH+=.inc\
        INCLUDEPATH+=./res/inc\
        INCLUDEPATH+=./ui/inc\
        RCC_DIR=./out/rcc\
        UI_DIR=./out/uic\
        QMAKE_CXXFLAGS+=-g\
        MOC_DIR=${KATALOG_MOC}\
        LIBS+=-lpthread\
        QT+=widgets\
        QT+=serialport



__start__: Makefile.app  __sprawdz_Qt__ ${NAZWA_APLIKACJI}
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


${NAZWA_APLIKACJI}: out/pro/${NAZWA_APLIKACJI}.pro __sprawdz__

__sprawdz__: 
	make -f Makefile.app

out/pro/${NAZWA_APLIKACJI}.pro: Makefile
	rm -f ${NAZWA_APLIKACJI}
	qmake -project -nopwd -o out/pro/${NAZWA_APLIKACJI}.pro\
               ${PODSTAWIENIA} ${ZRODLA_PROJEKTU} 

Makefile.app: out/pro/${NAZWA_APLIKACJI}.pro
	qmake -o Makefile.app out/pro/${NAZWA_APLIKACJI}.pro

project: __usun_pro__ out/pro/${NAZWA_APLIKACJI}.pro

__usun_pro__:
	rm -f out/pro/${NAZWA_APLIKACJI}.pro

__remove_bin__:
	rm -f ${NAZWA_APLIKACJI}

again:  __remove_bin__ __start__

clean: Makefile.app
	make -f Makefile.app clean
	if [ -d doc ]; then cd doc;  make clean; fi

cleanall: clean
	rm -f ${NAZWA_APLIKACJI}

cleantotally: cleanall
	rm -fr out/ Makefile.app
	find . \( -name \*~ -o -name \*.OLD -o -name \*.BAK \) -exec rm {} \;
	if [ -d doc ]; then cd doc; make cleantotally; fi

help:
	@echo "Subgoals:"
	@echo 
	@echo " project  - a project file is created"
	@echo " clean    - all compilation products are removed"
	@echo " cleanall - an aplication file and all compilation products are removed"
	@echo " cleantotally - except source files and Makfile all otehr files are removed"
	@echo " help     - this information is displayed"
	@echo
