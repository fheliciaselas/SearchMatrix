#include "MaxMatchSearcher.h"

#include<iostream>

MaxMatchSearcher::MaxMatchSearcher(){
    std::cout<<"Constructing MaxMatch Searcher Obj"<<std::endl;

}
MaxMatchSearcher::~MaxMatchSearcher(){
    std::cout<<"Destructing MaxMatch Searcher Obj"<<std::endl;
    
}

std::vector<int> MaxMatchSearcher::search(std::vector<int> &tosearch,std::vector< std::vector<int > > &matrix, std::unordered_map< unsigned int, std::unordered_map <int,unsigned int > >  &elementCountMap){
    clock_t start = clock() ;
    
    std::vector<int> rowsfound;
    //std::cout<<"Searching Max Match rows "<<std::endl;
     //rows
   // int max = 0;
   // std::unordered_map <unsigned int,std::unordered_map<int, unsigned int > >  e = elementCountMap;
    
   // int count =0;
    
    
    //;
    
    for(int i=0, s = elementCountMap.size(), max = 0;i<s;++i){ //for each row
        int count = 0;
        std::unordered_map<int, unsigned int > &temp = elementCountMap[i];
        for(int j=0, len = tosearch.size();j<len;++j){ //for the length of the substring
           
            int key = tosearch[j];
            if(temp.count(key) > 0){
                ++count;
                
            }
            
            if(count+len-1-j < max)
                break;
        }
        if(count > max){
            max = count;
            rowsfound.clear();
            rowsfound.push_back(i+1);
        }
        else if(count == max && count > 0){
            rowsfound.push_back(i+1);
        }
        
    }
    
    clock_t end = clock() ;
    /*if(rowsfound.size()==0)
        std::cout<<"Match not found in matrix"<<std::endl;
    else
    {
        std::cout<<"Max Matched found in row(s): ";
        for(int i = 0;i<rowsfound.size();i++)
            std::cout<<rowsfound[i]<<" ";
        std::cout<<std::endl;
    }*/
    float time = (float) (end - start) / CLOCKS_PER_SEC ;
    std::cout<<"Searching Time: "<<time<<" seconds"<<std::endl;
    return rowsfound;

}

