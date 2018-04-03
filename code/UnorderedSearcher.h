#include "Searcher.h"

#include<vector>
#include<unordered_map>


#ifndef UNORDEREDSEARCHER
#define UNORDEREDSEARCHER

class UnorderedSearcher : public Searcher{
    
public:
    UnorderedSearcher(std::vector< std::vector<int > > &m, std::unordered_map< int, std::unordered_map <int,int > >  &e);
    
    void search(std::vector<int> &tosearch);
    
    virtual ~UnorderedSearcher();
};

#endif


