#include "UnorderedSearcher.h"

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

UnorderedSearcher::UnorderedSearcher(vector< vector<int > > m, unordered_map< int, unordered_map <int,int > >  e):Searcher(m,e){
    
}

void UnorderedSearcher::search(vector<int> tosearch){
    
    int len = tosearch.size();
    vector<int> rowsfound;
    cout<<"Searching Unordered "<<endl;
    
    clock_t start = clock() ;
    
    int s = elementCountMap.size(); //rows
    
    for(int i=0;i<s;i++){ //for each row
        bool found = true;
        
        for(int j=0;j<len;j++){ //for len of substring
            int key = tosearch[j];
            if(elementCountMap[i].count(key) == 0 || elementCountMap[i][key] == 0){
                found = false;
                break;
            }
            else
                elementCountMap[i][key] -= 1;
        }
        if(found)
            rowsfound.push_back(i+1);
    }
    
    clock_t end = clock() ;
    float time = (float) (end - start) / CLOCKS_PER_SEC ;
    cout<<"Searching Time: "<<time<<" seconds"<<endl;
    if(rowsfound.size()==0)
        cout<<"Match not found in matrix"<<endl;
    else
    {
        for(int i = 0;i<rowsfound.size();i++)
            cout<<"Numbers found in row: "<<rowsfound[i]<<endl;
    }
}


