#include "UnorderedSearcher.h"

#include<iostream>
#include<vector>
#include<unordered_map>



UnorderedSearcher::UnorderedSearcher(std::vector<std::vector<int > > &m, std::unordered_map< int, std::unordered_map <int,int > >  &e):Searcher(m,e){
    
    std::cout<<"Creating Unordered Searcher Obj"<<std::endl;

}
UnorderedSearcher::~UnorderedSearcher(){

    std::cout<<"Destructing Unordered Searcher Obj"<<std::endl;
    
}
void UnorderedSearcher::search(std::vector<int> &tosearch){
    
    int len = tosearch.size();
   std::vector<int> rowsfound;
    std::cout<<"Searching Unordered "<<std::endl;
    
    
    int s = elementCountMap.size(); //rows
    std::unordered_map< int, std::unordered_map <int,int > >  e = elementCountMap;
    clock_t start = clock() ;
    
    for(int i=0;i<s;i++){ //for each row
        bool found = true;
        
        for(int j=0;j<len;j++){ //for len of substring
            int key = tosearch[j];
            if(e[i][key] == 0){
                found = false;
                break;
            }
            else
                e[i][key] -= 1;
        }
        if(found)
            rowsfound.push_back(i+1);
    }
    
    clock_t end = clock() ;
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


