slides.tex: pic/tdesc.tex pic/tdesc-new.tex

NON_ARM=slides.pdf slides-double-screen.pdf handout.pdf

$(NON_ARM): %.pdf: %.tex contents.tex
	pdflatex \\nonstopmode \\input $<
	pdflatex \\nonstopmode \\input $<

all: $(NON_ARM)

clean:
	-rm *.pdf *.aux *.nav *.snm *.toc
	-rm *.log  *.out
