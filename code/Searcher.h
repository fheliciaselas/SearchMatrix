#include<vector>
#include<unordered_map>

#ifndef SEARCHER
#define SEARCHER

class Searcher{
    
    public:
    
    Searcher();
    virtual ~Searcher();
    virtual std::vector<int> search(std::vector<int> &tosearch,std::vector< std::vector<int > > &matrix, std::unordered_map< unsigned int, std::vector < std::pair<int,int > > > &elementCountMap) = 0;
};

#endif
