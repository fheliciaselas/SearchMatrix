#include "Searcher.h"

#include<vector>
#include<unordered_map>

using namespace std;
#ifndef SEQUENCESEARCHER
#define SEQUENCESEARCHER

class SequenceSearcher : public Searcher{
    
public:
    SequenceSearcher(vector< vector<int > > m, unordered_map< int, unordered_map <int,int > >  e);
    
    void search(vector<int> tosearch);
    
};

#endif

