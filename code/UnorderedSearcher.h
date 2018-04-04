#include "Searcher.h"

#include<vector>
#include<unordered_map>


#ifndef UNORDEREDSEARCHER
#define UNORDEREDSEARCHER

class UnorderedSearcher : public Searcher{
    
public:
    UnorderedSearcher();
    
    void search(std::vector<int> &tosearch,std::vector< std::vector<int > > &matrix, std::unordered_map< unsigned int, std::unordered_map <int,unsigned int > >  &elementCountMap);
    
    virtual ~UnorderedSearcher();
};

#endif


