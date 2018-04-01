#include "Searcher.h"

#include<vector>
#include<unordered_map>

using namespace std;

#ifndef UNORDEREDSEARCHER
#define UNORDEREDSEARCHER

class UnorderedSearcher : public Searcher{
    
public:
    UnorderedSearcher(vector< vector<int > > m, unordered_map< int, unordered_map <int,int > >  e);
    
    void search(vector<int> tosearch);
    
};

#endif


