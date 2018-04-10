
#include "SequenceSearcher.h"

#include<iostream>
#include<algorithm>


SequenceSearcher::SequenceSearcher(){
    std::cout<<"Creating Sequence Searcher Obj"<<std::endl;

}
SequenceSearcher::~SequenceSearcher(){
    std::cout<<"Destructing Sequence Searcher Obj"<<std::endl;
}
std::vector<int> SequenceSearcher::search(std::vector<int> &tosearch,std::vector< std::vector<int > > &matrix, std::unordered_map< unsigned int, std::vector < std::pair<int,int > > > &elementCountMap){
    
    std::vector<int> count (matrix.size()); //create a count array of size = rows
    std::vector<int> orig = tosearch;
    std::sort(tosearch.begin(),tosearch.end()); //sort input search array (m log m)
    for(int i=0,len = tosearch.size();i<len;++i){ //for every element in the search array
        int ct =1;
        
        int &k = tosearch[i];
        while (k==tosearch[i+1] && i+1<len) {
            ++i;
            ++ct;  //count repetitions in search array
        }
        std::vector<std::pair<int, int > > &temp = elementCountMap[k]; // get the rownum,count pair of the key k
        
        for(int j=0,s=temp.size();j<s;j++){ // for all pairs corresponding to the key
            int rownum = temp[j].first;
            if(temp[j].second >= ct) //if the row has atleast count >= number of repetitions
                count[rownum] += ct; // increment count array
        }
        
    }
    std::vector<int> rowsfound;
    for(int j=0;j<count.size();j++){
        if(count[j]==tosearch.size()){ //if count array of row has value = length of input
            if(std::search(matrix[j].begin(), matrix[j].end(),orig.begin(), orig.end()) != matrix[j].end()){ // search in that row
                rowsfound.push_back(j+1); // add to result if sequence found in that row
                
            }
        }
    }
    
    return rowsfound;
}
