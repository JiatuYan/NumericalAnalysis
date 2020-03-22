default : homework1.pdf

%.pdf : %.tex
	pdflatex $<

clean : 
	$(RM) *.aux *.log

realclean :
	$(MAKE) clean
	$(RM) *.pdf
