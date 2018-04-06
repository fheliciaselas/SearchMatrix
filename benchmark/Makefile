BenchMarker:	BenchMarker.o ../code/SequenceSearcher.o ../code/UnorderedSearcher.o ../code/MaxMatchSearcher.o ../code/Searcher.o ../code/SearchFunction.o
	g++ -O2 -o BenchMarker BenchMarker.o ../code/SequenceSearcher.o ../code/UnorderedSearcher.o ../code/MaxMatchSearcher.o ../code/Searcher.o ../code/SearchFunction.o -std=c++11

BenchMarker.o:   ../code/SequenceSearcher.h  ../code/UnorderedSearcher.h  ../code/MaxMatchSearcher.h BenchMarker.cpp ../code/Searcher.h ../code/SearchFunction.h
	g++ -c -O2 BenchMarker.cpp -std=c++11


clean:
	@rm -f *.o
	@rm -f Benchmarker 
	@echo "Cleaning Files"


