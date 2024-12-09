all:
	(cd timerLib; make install)
	(cd lcdLib; make install)
	(cd wakedemo; make)
#	(cd circledemo; make)

load:
	(cd timerLib; make install)
	(cd lcdLib; make install)
	(cd project; make load)

doc:
	rm -rf doxygen_docs
	doxygen Doxyfile
clean:
	(cd timerLib; make clean)
	(cd lcdLib; make clean)
#	(cd circledemo; make clean)
	(cd wakedemo; make clean)
	(cd msquares; make clean)
	(cd project; make clean)
	rm -rf lib h
	rm -rf doxygen_docs/*
