#include "SearchFunction.h"
#include<string>
#include<vector>
#include<sstream>
#include<fstream>

void SearchFunction::search(std::vector<int> &tosearch, Searcher *s) {
    
    s->search(tosearch, matrix,elementCountMap);
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

void  SearchFunction::openAndParseData(char **argv){
    
    std::ifstream input_file;
    std::string rawdata,parsed;
    input_file.open(argv[1]); //opening the input file
    int row_count=0;
    
    if(input_file.is_open()){
        
        while(getline(input_file,rawdata)){
            
            std::unordered_map<int,unsigned int> temp;
            std::vector <int> row;
            parsed = decrypt(rawdata); //decrypting each row in the data
            std::istringstream iss(parsed);
            
            for(std::string s; iss >> s;){
                
                int x=0;
                std::stringstream ss(s);
                ss >> x; //write string to integer
                row.push_back(x); // push to std::vector 'row'
                if(temp.count(x)==0)  //check if element not present
                    temp[x] =1; // then set count to 1
                else
                    temp[x] = temp[x]+1; // increment count of element
                
            }
            
            elementCountMap[row_count] = temp; // map of count of elements added to key = row number
            matrix.push_back(row); // add the 'row' std::vector to the matrix
            ++row_count;
        }
        
    }
    
    input_file.close();
}

