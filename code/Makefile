MatrixSearcher:	MatrixSearcher.o SequenceSearcher.o UnorderedSearcher.o MaxMatchSearcher.o Searcher.o
	g++ -O2 -o MatrixSearcher MatrixSearcher.o SequenceSearcher.o UnorderedSearcher.o MaxMatchSearcher.o Searcher.o -std=c++11

MatrixSearcher.o:   SequenceSearcher.h  UnorderedSearcher.h  MaxMatchSearcher.h MatrixSearcher.cpp Searcher.h
	g++ -c -O2 MatrixSearcher.cpp -std=c++11

Searcher.o: Searcher.h Searcher.cpp
	g++ -c -O2 Searcher.cpp -std=c++11

SequenceSearcher.o: SequenceSearcher.h SequenceSearcher.cpp Searcher.h
	g++ -c -O2 SequenceSearcher.cpp -std=c++11

UnorderedSearcher.o:    UnorderedSearcher.h UnorderedSearcher.cpp Searcher.h
	g++ -c -O2 UnorderedSearcher.cpp -std=c++11

MaxMatchSearcher.o: MaxMatchSearcher.h MaxMatchSearcher.cpp Searcher.h
	g++ -c -O2 MaxMatchSearcher.cpp -std=c++11

clean:
	@rm *.o
	@rm MatrixSearcher
	@echo "Cleaning Files"

