#include "SearchFunction.h"
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<iostream>
#include<chrono>

double SearchFunction::benchmark_search(std::vector<int> &tosearch, Searcher *s) {
   
    
    
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    
    std::vector<int> rowsfound = s->search(tosearch, matrix,elementCountMap);
    
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double> diff = t2 - t1;
 
    return diff.count();
}

std::vector<int> SearchFunction::search(std::vector<int> &tosearch, Searcher *s) {
    
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    std::vector<int> rowsfound = s->search(tosearch, matrix,elementCountMap);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = t2 - t1;
    
    std::cout<<"Searching Time: "<<diff.count()*1000000<<" micro seconds"<<std::endl;
    
    
    if(rowsfound.size()==0)
        std::cout<<"Not found in matrix"<<std::endl;
    else
    {
        std::cout<<"Found in row(s): ";
        for(int i = 0;i<rowsfound.size();i++)
            std::cout<<rowsfound[i]<<" ";
        std::cout<<std::endl;
    }
    
    return rowsfound;
    
}


SearchFunction::SearchFunction(){
    
}

SearchFunction::~SearchFunction(){
    
}

std::string SearchFunction::decrypt(std::string raw_text)
{
    const char key = 'N';
    std::string output = raw_text;
    int len = output.size();
    for(int i=0;i<len;++i){
        output[i] = raw_text[i] ^ key;
    }
    
    return output;
}

void  SearchFunction::openAndParseData(char *argv){
    
    std::ifstream input_file;
    std::string rawdata,parsed;
    input_file.open(argv); //opening the input file
    
    if(input_file.is_open()){
        
        while(getline(input_file,rawdata)){
            
            std::vector <int > row;
            parsed = decrypt(rawdata); //decrypting each row in the data
            std::istringstream iss(parsed);
            
            for(std::string s; iss >> s;){
                
                int x=0;
                std::stringstream ss(s);
                ss >> x; //write string to integer
                row.push_back(x); // push to std::vector 'row'
                
            }
            
           matrix.push_back(row); // add the 'row' std::vector to the matrix
        }
        int s = matrix.size();
        for(int i=0;i<s;i++)
        {
            int l =matrix[i].size();
            
            for(int j=0;j<l;j++){
                std::vector< std::pair<int,int > > &temp = elementCountMap[matrix[i][j]];
                bool found = false;
                for(int k=0;k<temp.size();k++){
                    if(temp[k].first == i){
                        found = true;
                        temp[k].second +=1;
                    }
                    
                }
                if(!found){
                    temp.push_back(std::make_pair(i,1));
                }
            }
        }
    }
    else
        std::cout<<"Unable to openfile"<<std::endl;
    
    input_file.close();
}

