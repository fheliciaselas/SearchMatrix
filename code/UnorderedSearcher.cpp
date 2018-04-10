#include "UnorderedSearcher.h"
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>


UnorderedSearcher::UnorderedSearcher(){
    
    std::cout<<"Creating Unordered Searcher Obj"<<std::endl;

}
UnorderedSearcher::~UnorderedSearcher(){

    std::cout<<"Destructing Unordered Searcher Obj"<<std::endl;
    
}
std::vector<int> UnorderedSearcher::search(std::vector<int> &tosearch,std::vector< std::vector<int > > &matrix,std::unordered_map< unsigned int, std::vector < std::pair<int,int > > > &elementCountMap){
    
    std::vector<int> count (matrix.size()); //create a count array of size = rows
    std::sort(tosearch.begin(),tosearch.end()); //sort input search array (m log m)
    for(int i=0,len = tosearch.size();i<len;++i){ //for every element in the search array
        int ct =1;
        
        int &k = tosearch[i];
        while (k==tosearch[i+1] && i+1<len) { //count repetitions in search array
            ++i;
            ++ct;
        }
        std::vector<std::pair<int, int > > &temp = elementCountMap[k]; // get the rownum,count pair of the key k
        
        for(int j=0,s=temp.size();j<s;j++){ // for all pairs corresponding to the key
            
            int rownum = temp[j].first;
            if(temp[j].second >= ct) //if the row has atleast count >= number of repetitions
                count[rownum] += ct; // increment count array
        }
    
    }
    std::vector<int> rowsfound;
    for(int j=0;j<count.size();j++)
        if(count[j]==tosearch.size())  //if count array of row has value = length of input array
            rowsfound.push_back(j+1); // add row to result
   
    return rowsfound;
   
}


