#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<boost/algorithm/searching/knuth_morris_pratt.hpp>
#include<string>
#include<time.h>
#include<map>
#include<unordered_map>

#include "SequenceSearcher.h"
#include "UnorderedSearcher.h"
#include "MaxMatchSearcher.h"

std::map<std::string, Searcher *> searchmap;

std::string decrypt(std::string raw_text)
{
    const char key = 'N';
    std::string output = raw_text;
    int len = output.size();
    for(int i=0;i<len;i++){
        output[i] = raw_text[i] ^ key;
    }
    
    return output;
}

void listAvailableCommands(){
    
    std::cout<<std::endl<<"Available Commands are: "<<std::endl;
    std::cout<<std::endl;
    std::cout<<"1. searchSequence "<<std::endl<<"2. searchUnordered "<<std::endl<<"3. searchMaxMatch "<<std::endl<<"4. exit "<<std::endl<<std::endl;
    std::cout<<"usage example: searchSequence 1 2 3"<<std::endl;
}

void printRunCommand(){
    std::cout<<std::endl<<"Please specify input file name"<<std::endl;
    std::cout<<std::endl<<"Run as ./MatrixSearcher ../inputfile/test.txt"<<std::endl;
}

void  openAndParseData(char **argv, std::unordered_map< int, std::unordered_map <int,int > >  &elementCountMap, std::vector < std::vector <int > > &matrix ){
    
    std::ifstream input_file;
    std::string rawdata,parsed;
    input_file.open(argv[1]); //opening the input file
    int row_count=0;
    
    if(input_file.is_open()){
        
        while(getline(input_file,rawdata)){
            
            std::unordered_map<int,int> temp;
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
            row_count++;
        }
        
    }
    
    input_file.close();
}

void parseCommandInput(std::string &cmd,std::vector<int> &tosearch,std::string &line, bool &allnumbers){
    
    int found=0,pos=0;
    bool first = false;
    while((found = line.find_first_of(' ',pos))!= std::string::npos){
        
        std::string s = line.substr(pos,found - pos);
        if(!first){
            cmd = s;
            first = true;
        }
        else
        {
            std::stringstream tmp(s);
            int x = 0;
            tmp >> x;
            if(std::to_string(x) != s)
            {
                std::cerr<<std::endl<<"ERROR: Invalid input"<<std::endl;
                allnumbers = false;
                return;
            }
            else
                tosearch.push_back(x);
        }
        pos = found+1;
    }
    if(!first){
        cmd = line.substr(pos);
    }
    else{
        std::stringstream tmp(line.substr(pos));
        int x = 0;
        tmp >> x;
        tosearch.push_back(x);
    }
}


void createMap(std::vector< std::vector<int > > &matrix, std::unordered_map< int, std::unordered_map <int,int > >  &elementCountMap){
 
    searchmap["searchSequence"]= new SequenceSearcher(matrix,elementCountMap);
    searchmap["searchUnordered"]= new UnorderedSearcher(matrix,elementCountMap);
    searchmap["searchMaxMatch"]= new MaxMatchSearcher(matrix,elementCountMap);

}

void freemap(){
    for(auto it = searchmap.begin();it!=searchmap.end();it++){
        delete it->second;
    }
}

int main(int argc, char **argv){

    std::vector< std::vector<int > > matrix;  // 2D representation of matrix
    std::unordered_map <int,std::unordered_map<int,int> > elementCountMap; //count of each element in a row in the matrix
    
    bool allnumbers;    //to check if entered integers are all numbers
    bool exitcmd = false; // command 'exit' has not been entered till now
    
    if(argc < 2) //If Input file not entered
    {
        printRunCommand();
        return -1;
    }
    
    listAvailableCommands(); //list all available search options
    
    std::cout<<"Decrypting input file and parsing. Please wait for completion"<<std::endl;
    openAndParseData(argv, elementCountMap,matrix); // decrypt the text file and store in map in memory //pass by ref
    std::cout<<"End parsing"<<std::endl;
    
    createMap(matrix,elementCountMap); //pass by ref
    Searcher *s;
    while(!exitcmd){
        
        std::string cmd,line;
        std::vector<int> tosearch; // sequence or numbers to be searched
        
        std::cout<<std::endl<<"Enter command: "<<std::endl;
        getline(std::cin,line);
        allnumbers = true;
        parseCommandInput(cmd,tosearch,line,allnumbers); //parse line to seperate command from numbers.
        //also check if all are integers //pass by ref
        
        if(!allnumbers)
            std::cerr<<"ERROR : Please enter only integers"<<std::endl;
        else if(tosearch.size()==0 && cmd !="exit")
            std::cerr<<std::endl<<"ERROR: Please input integers to search"<<std::endl;
        else if(cmd =="exit")
            exitcmd = true; //exit program
        
         
        else
        {
            s = searchmap[cmd];
            if(s==NULL)
                std::cout<<"Invalid Command"<<std::endl;
            else
                s->search(tosearch);
        }
        
        
    }
    s=NULL;
    delete s;
    freemap();
    
    
    
    
}



