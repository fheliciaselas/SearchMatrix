#include "Searcher.h"

#include<vector>
#include<unordered_map>


#ifndef SEQUENCESEARCHER
#define SEQUENCESEARCHER

class SequenceSearcher : public Searcher{
    
public:
    SequenceSearcher();
    
   std::vector<int> search(std::vector<int> &tosearch,std::vector< std::vector<int > > &matrix, std::unordered_map< unsigned int, std::unordered_map <int,unsigned int > >  &elementCountMap);
    
    virtual ~SequenceSearcher();
};

#endif

