#include<vector>
#include<unordered_map>

#ifndef SEARCHER
#define SEARCHER

class Searcher{
    
    protected:
        const std::vector< std::vector<int > > &matrix;
        const std::unordered_map< int, std::unordered_map <int,int > >  &elementCountMap;
    
    public:
    
    Searcher(std::vector< std::vector<int > > &m, std::unordered_map< int, std::unordered_map <int,int > >  &e);
    virtual ~Searcher();
    virtual void search(std::vector<int> &) = 0;
};

#endif
