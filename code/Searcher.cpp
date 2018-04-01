#include <iostream>
using namespace std;

#include "Searcher.h"

Searcher::Searcher(vector< vector<int > > m, unordered_map< int, unordered_map <int,int > >  e){
    
    matrix = m;
    elementCountMap = e;
    cout<<"Initializing Matrix Information"<<endl;
}

Searcher::~Searcher(){
    cout<<"Destructing Searcher";
}
