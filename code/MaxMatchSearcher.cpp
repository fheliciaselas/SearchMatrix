#include "MaxMatchSearcher.h"

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

MaxMatchSearcher::MaxMatchSearcher(vector< vector<int > > m, unordered_map< int, unordered_map <int,int > >  e):Searcher(m,e){
    
}

void MaxMatchSearcher::search(vector<int> tosearch){
    
    int len = tosearch.size();
    vector<int> rowsfound;
    cout<<"Searching Max Match rows "<<endl;
    int s = elementCountMap.size(); //rows
    int maxrow = -1, max = 0;
    
    clock_t start = clock() ;
    for(int i=0;i<s;i++){ //for each row
        int count = 0;
        for(int j=0;j<len;j++){ //for the length of the substring
            if(elementCountMap[i][tosearch[j]] > 0){
                ++count;
                elementCountMap[i][tosearch[j]] -= 1;
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
    cout<<"Searching Time: "<<time<<" seconds"<<endl;
    if(rowsfound.size()==0)
        cout<<"Match not found in matrix"<<endl;
    else
    {
        cout<<"Max Matched found in row(s): ";
        for(int i = 0;i<rowsfound.size();i++)
            cout<<rowsfound[i]<<" ";
        cout<<endl;
    }
    

}

