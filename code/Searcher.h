#include<vector>
#include<unordered_map>

#ifndef SEARCHER
#define SEARCHER

class Searcher{
    
    public:
    
    Searcher();
    virtual ~Searcher();
    virtual void search(std::vector<int> &tosearch,std::vector< std::vector<int > > &matrix, std::unordered_map< unsigned int, std::unordered_map <int,unsigned int > >  &elementCountMap) = 0;
};

#endif
