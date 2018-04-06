#include<vector>
#include<unordered_map>

#include "Searcher.h"
#ifndef SEARCHFUNCTION
#define SEARCHFUNCTION


class SearchFunction{
    
private:
     std::vector< std::vector<int > > matrix;
     std::unordered_map< unsigned int, std::unordered_map <int,unsigned int > >  elementCountMap;
    std::string decrypt(std::string raw_text);
    
public:
    
    SearchFunction();
    virtual ~SearchFunction();
    double benchmark_search(std::vector<int> &tosearch, Searcher *s) ;
    std::vector<int> search(std::vector<int> &tosearch, Searcher *s) ;
    void openAndParseData(char *argv);
        
};

#endif

