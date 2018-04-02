#include "Searcher.h"


#include<vector>
#include<unordered_map>


#ifndef MAXMATCHSEARCHER
#define MAXMATCHSEARCHER

class MaxMatchSearcher : public Searcher{
    
public:
    MaxMatchSearcher(std::vector< std::vector<int > > m, std::unordered_map< int, std::unordered_map <int,int > >  e);
    
    void search(std::vector<int> tosearch);
    
};

#endif



