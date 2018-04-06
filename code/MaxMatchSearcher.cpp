#include "MaxMatchSearcher.h"

#include<iostream>

MaxMatchSearcher::MaxMatchSearcher(){
    std::cout<<"Constructing MaxMatch Searcher Obj"<<std::endl;

}
MaxMatchSearcher::~MaxMatchSearcher(){
    std::cout<<"Destructing MaxMatch Searcher Obj"<<std::endl;
    
}
/*
std::vector<int> MaxMatchSearcher::search(std::vector<int> &tosearch,std::vector< std::vector<int > > &matrix, std::unordered_map< unsigned int, std::unordered_map <int,unsigned int > >  &elementCountMap){
    
    int maxrow = -1, len = tosearch.size();
    std::unordered_map<unsigned int,unsigned int> count_search;
    for (int j=0,len = tosearch.size();j<len;j++){
        ++count_search[tosearch[j]];
    }
    
    for(int i=0, s = elementCountMap.size(), max = 0;i<s;++i){ //for each row
        int count = 0;
        std::unordered_map<int, unsigned int > &temp = elementCountMap[i];
        for (auto it = count_search.begin(); it != count_search.end(); it++) {
           int key = it->first;
            
            auto tx = temp.find(key);
            if(tx != temp.end())
            {
                int v1 = tx->second, v2 = it->second;
                if(v1 < v2)
                    count = count + v1;
                else
                    count = count + v2;
            }
           
        }
        if(count > max){
            max = count;
            maxrow = i+1;
        }
        
        
    }
    std::vector<int> rowsfound;
    if(maxrow > 0)
        rowsfound.push_back(maxrow);
    return rowsfound;
}*/
std::vector<int> MaxMatchSearcher::search(std::vector<int> &tosearch,std::vector< std::vector<int > > &matrix, std::unordered_map< unsigned int, std::unordered_map <int,unsigned int > >  &elementCountMap){
 
    int maxrow = -1;
 
    std::sort(tosearch.begin(),tosearch.end());
    
    for(int i=0, s = elementCountMap.size(), max = 0;i<s;++i){ //for each row
        int count = 0;
        std::unordered_map<int, unsigned int > &temp = elementCountMap[i];
        for(int j=0, len = tosearch.size();j<len;++j){ //for the length of the substring
            
                const unsigned int &key = tosearch[j];
                if(temp.count(key) == 0){
                    
                    while(tosearch[j+1] == key && (j+1) < len)
                        ++j;
                    continue;
                }
                else{
                    int tc = 1;
                    
                    while(tosearch[j+1] == key && (j+1) < len)
                    {
                        ++j;
                        ++tc;
                    }
                    unsigned int &val = temp[key];
                    if(tc<= val)
                        count += tc;
                    else
                        count += val;
                }
 
                if(count+len-1-j < max)
                    break;
        }
        if(count > max){
            max = count;
            maxrow = i+1;
        }
    }
    std::vector<int> rowsfound;
    if(maxrow > 0)
        rowsfound.push_back(maxrow);
    return rowsfound;
}
