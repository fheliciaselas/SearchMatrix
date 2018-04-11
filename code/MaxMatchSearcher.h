#include "Searcher.h"

#ifndef MAXMATCHSEARCHER
#define MAXMATCHSEARCHER

class MaxMatchSearcher : public Searcher{
    
public:
    MaxMatchSearcher();
    
    std::vector<int> search (std::vector<int> &tosearch,std::vector< std::vector<int > > &matrix, std::unordered_map< unsigned int, std::vector < std::pair<int,int > > >  &elementCountMap);
    
    virtual ~MaxMatchSearcher();
    
};

#endif



