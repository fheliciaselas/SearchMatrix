#include "Searcher.h"

#ifndef UNORDEREDSEARCHER
#define UNORDEREDSEARCHER

class UnorderedSearcher : public Searcher{
    
public:
    UnorderedSearcher();
    
    std::vector<int> search (std::vector<int> &tosearch,std::vector< std::vector<int > > &matrix, std::unordered_map< unsigned int, std::vector < std::pair<int,int > > > &elementCountMap);
    
    virtual ~UnorderedSearcher();
};

#endif


