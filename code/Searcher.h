#include<vector>
#include<unordered_map>

using namespace std;

#ifndef SEARCHER
#define SEARCHER

class Searcher{
    
    public:
        vector< vector<int > > matrix;
        unordered_map< int, unordered_map <int,int > >  elementCountMap;
    
    
    Searcher(vector< vector<int > > m, unordered_map< int, unordered_map <int,int > >  e);

   virtual ~Searcher();
    
    virtual void search(vector<int>) = 0;
};

#endif
