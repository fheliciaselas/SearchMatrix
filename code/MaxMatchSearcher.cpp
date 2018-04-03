#include "MaxMatchSearcher.h"

#include<iostream>

MaxMatchSearcher::MaxMatchSearcher(std::vector< std::vector<int > > &m, std::unordered_map< int, std::unordered_map <int,int > >  &e):Searcher(m,e){
    std::cout<<"Constructing MaxMatch Searcher Obj"<<std::endl;

}
MaxMatchSearcher::~MaxMatchSearcher(){
    std::cout<<"Destructing MaxMatch Searcher Obj"<<std::endl;
    
}

void MaxMatchSearcher::search(std::vector<int> &tosearch){
    
    int len = tosearch.size();
    std::vector<int> rowsfound;
    std::cout<<"Searching Max Match rows "<<std::endl;
    int s = elementCountMap.size(); //rows
    int maxrow = -1, max = 0;
    std::unordered_map< int, std::unordered_map <int,int > >  e = elementCountMap;

    clock_t start = clock() ;
    for(int i=0;i<s;i++){ //for each row
        int count = 0;
        for(int j=0;j<len;j++){ //for the length of the substring
            if(e[i][tosearch[j]] > 0){
                ++count;
                e[i][tosearch[j]] -= 1;
            }
        }
        if(count > max){
            max = count;
            rowsfound.clear();
            rowsfound.push_back(i+1);
        }
        else if(count > 0 && count == max){
            rowsfound.push_back(i+1);
        }
        
    }
    
    clock_t end = clock() ;
    float time = (float) (end - start) / CLOCKS_PER_SEC ;
    std::cout<<"Searching Time: "<<time<<" seconds"<<std::endl;
    if(rowsfound.size()==0)
        std::cout<<"Match not found in matrix"<<std::endl;
    else
    {
        std::cout<<"Max Matched found in row(s): ";
        for(int i = 0;i<rowsfound.size();i++)
            std::cout<<rowsfound[i]<<" ";
        std::cout<<std::endl;
    }
    

}

