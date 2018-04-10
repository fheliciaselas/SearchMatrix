#include "MaxMatchSearcher.h"

#include<iostream>
#include<algorithm>

MaxMatchSearcher::MaxMatchSearcher(){
    std::cout<<"Constructing MaxMatch Searcher Obj"<<std::endl;

}
MaxMatchSearcher::~MaxMatchSearcher(){
    std::cout<<"Destructing MaxMatch Searcher Obj"<<std::endl;
    
}

std::vector<int> MaxMatchSearcher::search(std::vector<int> &tosearch,std::vector< std::vector<int > > &matrix, std::unordered_map< unsigned int, std::vector < std::pair<int,int > > > &elementCountMap){
 
   
 
    std::vector<int> count (matrix.size()); //create a count array of size = rows
    std::sort(tosearch.begin(),tosearch.end()); //sort input search array (m log m)
    for(int i=0,len = tosearch.size();i<len;++i){ //for every element in the search array
        int ct =1;
        
        int &k = tosearch[i];
        while (k==tosearch[i+1] && i+1<len) {
            ++i;
            ++ct; //count repetitions in search array
        }
        std::vector<std::pair<int, int > > &temp = elementCountMap[k];  // get the rownum,count pair of the key k
        
        for(int j=0,s=temp.size();j<s;j++){ // for all pairs corresponding to the key
            int rownum = temp[j].first;
            int cnt = temp[j].second;
            if(cnt >= ct)                   // if row has the value greater than or equal to the number of repetitions
                count[rownum] += ct; // add number of repetitions
            else
                count[rownum] += cnt; //if row has less than the number of repetitions, add the repetitions in the row
        }
        
    }
    int max=0,maxrow = -1;
    
    for(int j=0,len = tosearch.size(),s =count.size() ;j<s;j++)
    {
        if(count[j] > max){
            max = count[j];
            maxrow = j+1; //max row
            
        }
    }
    
    std::vector<int> rowsfound;
    if(maxrow > 0)
        rowsfound.push_back(maxrow);
    return rowsfound;
}
