MatrixSearcher:	MatrixSearcher.o SequenceSearcher.o UnorderedSearcher.o MaxMatchSearcher.o Searcher.o
	g++ -o MatrixSearcher MatrixSearcher.o SequenceSearcher.o UnorderedSearcher.o MaxMatchSearcher.o Searcher.o

MatrixSearcher.o:   SequenceSearcher.h  UnorderedSearcher.h  MaxMatchSearcher.h MatrixSearcher.cpp Searcher.h
	g++ -c MatrixSearcher.cpp

Searcher.o: Searcher.h Searcher.cpp
	g++ -c Searcher.cpp

SequenceSearcher.o: SequenceSearcher.h SequenceSearcher.cpp Searcher.h
	g++ -c SequenceSearcher.cpp

UnorderedSearcher.o:    UnorderedSearcher.h UnorderedSearcher.cpp Searcher.h
	g++ -c UnorderedSearcher.cpp

MaxMatchSearcher.o: MaxMatchSearcher.h MaxMatchSearcher.cpp Searcher.h
	g++ -c MaxMatchSearcher.cpp

clean:
	@rm *.o
	@rm MatrixSearcher
	@echo "Cleaning Files"

