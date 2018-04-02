
#include "SequenceSearcher.h"

#include<iostream>
#include<vector>
#include<unordered_map>
#include<boost/algorithm/searching/knuth_morris_pratt.hpp>



SequenceSearcher::SequenceSearcher(std::vector<std::vector<int > > m, std::unordered_map< int, std::unordered_map <int,int > >  e):Searcher(m,e){
    
}

void SequenceSearcher::search(std::vector<int> tosearch){
    
    int rows = matrix.size();
    int len = tosearch.size();
   std::vector<int> rowsfound;
    int s = elementCountMap.size();
    
    clock_t start = clock() ;
    
    
    for(int i=0;i<s;i++){ //for each row
        bool found = true;
        
        for(int j=0;j<len;j++){
            int key = tosearch[j];
            if(elementCountMap[i].count(key) == 0 || elementCountMap[i][key] == 0){
                found = false;
                break;
            }
            else
                elementCountMap[i][key] -= 1;
        }
        if(found)
        {
            if(boost::algorithm::knuth_morris_pratt_search(matrix[i].begin(), matrix[i].end(),tosearch.begin(), tosearch.end()).first != matrix[i].end()){
                rowsfound.push_back(i+1);
            }
            
        }
    }
    clock_t end  = clock() ;
    
    if(rowsfound.size()==0)
        std::cout<<"Match not found in matrix"<<std::endl;
    else
    {
        for(int i = 0;i<rowsfound.size();i++)
            std::cout<<"Numbers found in row: "<<rowsfound[i]<<std::endl;
    }
    float time = (float) (end - start) / CLOCKS_PER_SEC ;
    std::cout<<"Searching Time: "<<time<<" seconds"<<std::endl;
}
