#include "Searcher.h"


#include<vector>
#include<unordered_map>


#ifndef MAXMATCHSEARCHER
#define MAXMATCHSEARCHER

class MaxMatchSearcher : public Searcher{
    
public:
    MaxMatchSearcher();
    
    void search(std::vector<int> &tosearch,std::vector< std::vector<int > > &matrix, std::unordered_map< unsigned int, std::unordered_map <int,unsigned int > >  &elementCountMap);
    
    virtual ~MaxMatchSearcher();
    
};

#endif



