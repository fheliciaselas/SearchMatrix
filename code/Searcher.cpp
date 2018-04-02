#include <iostream>

#include "Searcher.h"

Searcher::Searcher(std::vector< std::vector<int > > m, std::unordered_map< int, std::unordered_map <int,int > >  e){
    
    matrix = m;
    elementCountMap = e;
    std::cout<<"Initializing Matrix Information"<<std::endl;
}

Searcher::~Searcher(){
    std::cout<<"Destructing Searcher";
}
