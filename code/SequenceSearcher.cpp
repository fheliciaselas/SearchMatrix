
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
std::vector<int> SequenceSearcher::search(std::vector<int> &tosearch,std::vector< std::vector<int > > &matrix, std::unordered_map< unsigned int, std::unordered_map <int,unsigned int > >  &elementCountMap){
    
    std::vector<int> rowsfound;
    
    clock_t start = clock() ;
    
    for(int i=0,s = elementCountMap.size();i<s;++i){ //for each row
        bool found = true;
        std::unordered_map<int, unsigned int > &temp = elementCountMap[i];
        for(int j=0,len = tosearch.size();j<len;++j){ //for len of substring
            int key = tosearch[j];
            
            if(temp.count(key) == 0 || temp[key] < std::count(tosearch.begin(),tosearch.end(),key)){

                found = false;
                break;
            }
            
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
    
   /* if(rowsfound.size()==0)
        std::cout<<"Match not found in matrix"<<std::endl;
    else
    {
        for(int i = 0;i<rowsfound.size();++i)
            std::cout<<"Numbers found in row: "<<rowsfound[i]<<std::endl;
    }*/
    float time = (float) (end - start) / CLOCKS_PER_SEC ;
    std::cout<<"Searching Time: "<<time<<" seconds"<<std::endl;
    
    return rowsfound;
}
