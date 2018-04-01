#include "SequenceSearcher.h"

#include<iostream>
#include<vector>
#include<unordered_map>
#include<boost/algorithm/searching/knuth_morris_pratt.hpp>

using namespace std;


SequenceSearcher::SequenceSearcher(vector< vector<int > > m, unordered_map< int, unordered_map <int,int > >  e):Searcher(m,e){
    
}

void SequenceSearcher::search(vector<int> tosearch){
    
    int rows = matrix.size();
    int len = tosearch.size();
    vector<int> rowsfound;
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
        cout<<"Match not found in matrix"<<endl;
    else
    {
        for(int i = 0;i<rowsfound.size();i++)
            cout<<"Numbers found in row: "<<rowsfound[i]<<endl;
    }
    float time = (float) (end - start) / CLOCKS_PER_SEC ;
    cout<<"Searching Time: "<<time<<" seconds"<<endl;
}
