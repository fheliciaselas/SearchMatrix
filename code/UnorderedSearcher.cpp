#include "UnorderedSearcher.h"

#include<iostream>
#include<vector>
#include<unordered_map>



UnorderedSearcher::UnorderedSearcher(){
    
    std::cout<<"Creating Unordered Searcher Obj"<<std::endl;

}
UnorderedSearcher::~UnorderedSearcher(){

    std::cout<<"Destructing Unordered Searcher Obj"<<std::endl;
    
}
std::vector<int> UnorderedSearcher::search(std::vector<int> &tosearch,std::vector< std::vector<int > > &matrix, std::unordered_map< unsigned int, std::unordered_map <int,unsigned int > >  &elementCountMap){
    
   std::vector<int> rowsfound;
    std::unordered_map<int,int> count_search;
    for (int j=0,len = tosearch.size();j<len;j++){
        ++count_search[tosearch[j]];
    }
    for(int i=0,s = elementCountMap.size();i<s;++i){ //for each row
        bool found = true;
        std::unordered_map<int, unsigned int > &temp = elementCountMap[i];
        //for(int j=0,len = tosearch.size();j<len;++j){ //for len of substring
        for (auto it = count_search.begin(); it != count_search.end(); it++) {
            int key = it->first;
            
            if(temp.count(key) == 0 || temp[key] < it->second){
                found = false;
                break;
            }
        }
        if(found)
            rowsfound.push_back(i+1);
    }
    return rowsfound;
   
}


