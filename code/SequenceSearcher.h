#include "Searcher.h"


#ifndef SEQUENCESEARCHER
#define SEQUENCESEARCHER

class SequenceSearcher : public Searcher{
    
public:
    SequenceSearcher();
    
   std::vector<int> search (std::vector<int> &tosearch,std::vector< std::vector<int > > &matrix, std::unordered_map< unsigned int, std::vector < std::pair<int,int > > > &elementCountMap);
    
    virtual ~SequenceSearcher();
};

#endif

