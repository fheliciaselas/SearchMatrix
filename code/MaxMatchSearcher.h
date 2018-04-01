#include "Searcher.h"


#include<vector>
#include<unordered_map>

using namespace std;

#ifndef MAXMATCHSEARCHER
#define MAXMATCHSEARCHER

class MaxMatchSearcher : public Searcher{
    
public:
    MaxMatchSearcher(vector< vector<int > > m, unordered_map< int, unordered_map <int,int > >  e);
    
    void search(vector<int> tosearch);
    
};

#endif



