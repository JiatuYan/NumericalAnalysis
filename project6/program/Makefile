default : program.pdf

%.pdf : %.tex
	pdflatex $<

clean : 
	$(RM) *.aux *.log

realclean :
	$(MAKE) clean
	$(RM) *.pdf
