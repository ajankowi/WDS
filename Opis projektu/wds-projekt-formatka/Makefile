FILE=wds-projekt


__showpdf__: $(FILE).pdf
	evince $(FILE).pdf&


again: __compile__

bib: __make_bib__ __compile__


$(FILE).pdf: $(FILE).tex
	TEXINPUTS="sty:${TEXINPUTS}"; export TEXINPUTS; pdflatex $(FILE)

__make_bib__:
	export BIBINPUTS TEXINPUTS; TEXINPUTS="sty:${TEXINPUTS}"; BIBINPUTS="./bib:${BIBINPUTS}"; bibtex ${FILE}


__compile__:
	@echo
	@echo
	@echo
	@echo
	@echo
	TEXINPUTS="sty:${TEXINPUTS}"; export TEXINPUTS; pdflatex $(FILE)



clean:
	rm -f *.dvi *.aux *.log *.blg *.bbl *.out *.toc

help:
	@echo "Lista akceptowanych podcelow:"
	@echo 
	@echo " clean  - usuniecie plikow pomocniczych"
	@echo " again  - bezwarunkowe wymuszenie ponownej kompilacji dokumentu"
	@echo " bib    - uruchomienie i bibtex'a i powtorna kompilacja"
	@echo

