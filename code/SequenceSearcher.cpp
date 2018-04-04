
#include "SequenceSearcher.h"

#include<iostream>
#include<vector>
#include<unordered_map>
//#include<boost/algorithm/searching/knuth_morris_pratt.hpp>
#include<algorithm>


SequenceSearcher::SequenceSearcher(){
    std::cout<<"Creating Sequence Searcher Obj"<<std::endl;

}
SequenceSearcher::~SequenceSearcher(){
    std::cout<<"Destructing Sequence Searcher Obj"<<std::endl;
}
void SequenceSearcher::search(std::vector<int> &tosearch,std::vector< std::vector<int > > &matrix, std::unordered_map< unsigned int, std::unordered_map <int,unsigned int > >  &elementCountMap){
    
    int len = tosearch.size();
   std::vector<int> rowsfound;
    int s = elementCountMap.size();
    std::unordered_map <unsigned int,std::unordered_map<int, unsigned int > >  e = elementCountMap;
    clock_t start = clock() ;
    
    
    for(int i=0;i<s;++i){ //for each row
        bool found = true;
        
        for(int j=0;j<len;++j){
            int key = tosearch[j];
            if(e[i].count(key) == 0 || e[i][key] == 0){
                found = false;
                break;
            }
            else
                e[i][key] -= 1;
        }
        if(found)
        {
            //if(boost::algorithm::knuth_morris_pratt_search(matrix[i].begin(), matrix[i].end(),tosearch.begin(), tosearch.end()).first != matrix[i].end()){ // need gcc 5.5 +
            if(std::search(matrix[i].begin(), matrix[i].end(),tosearch.begin(), tosearch.end()) != matrix[i].end()){
                
                rowsfound.push_back(i+1);
            }
            
        }
    }
    clock_t end  = clock() ;
    
    if(rowsfound.size()==0)
        std::cout<<"Match not found in matrix"<<std::endl;
    else
    {
        for(int i = 0;i<rowsfound.size();++i)
            std::cout<<"Numbers found in row: "<<rowsfound[i]<<std::endl;
    }
    float time = (float) (end - start) / CLOCKS_PER_SEC ;
    std::cout<<"Searching Time: "<<time<<" seconds"<<std::endl;
}
