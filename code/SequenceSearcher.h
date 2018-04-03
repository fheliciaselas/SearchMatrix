#include "Searcher.h"

#include<vector>
#include<unordered_map>


#ifndef SEQUENCESEARCHER
#define SEQUENCESEARCHER

class SequenceSearcher : public Searcher{
    
public:
    SequenceSearcher(std::vector< std::vector<int > > &m, std::unordered_map< int, std::unordered_map <int,int > >  &e);
    
    void search(std::vector<int> &tosearch);
    
    virtual ~SequenceSearcher();
};

#endif

