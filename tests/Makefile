TestSearch:	TestSearch.o ../code/SequenceSearcher.o ../code/UnorderedSearcher.o ../code/MaxMatchSearcher.o ../code/Searcher.o ../code/SearchFunction.o
	g++ -O2 -o TestSearch TestSearch.o ../code/SequenceSearcher.o ../code/UnorderedSearcher.o ../code/MaxMatchSearcher.o ../code/Searcher.o ../code/SearchFunction.o -std=c++11

TestSearch.o:   ../code/SequenceSearcher.h  ../code/UnorderedSearcher.h  ../code/MaxMatchSearcher.h TestSearch.cpp ../code/Searcher.h ../code/SearchFunction.h
	g++ -c -O2 TestSearch.cpp -std=c++11


clean:
	@rm -f *.o
	@rm -f TestSearch
	@echo "Cleaning Files"


