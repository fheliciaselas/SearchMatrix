#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<string>
#include<time.h>
#include<unordered_map>
#include<map>
#include "SequenceSearcher.h"
#include "UnorderedSearcher.h"
#include "MaxMatchSearcher.h"
#include "SearchFunction.h"

std::map<std::string, Searcher *> searchmap;



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
    std::string s= line.substr(pos);
    if(!first){
        cmd = s;
    }
    else{
        
        std::stringstream tmp(s);
        int x = 0;
        tmp >> x;
        if(std::to_string(x) == s)
            tosearch.push_back(x);
    }
}


void createMap(){
 
    searchmap["searchSequence"]= new SequenceSearcher();
    searchmap["searchUnordered"]= new UnorderedSearcher();
    searchmap["searchMaxMatch"]= new MaxMatchSearcher();

}

void freemap(){
    for(auto it = searchmap.begin();it!=searchmap.end();++it){
        delete it->second;
    }
}

int main(int argc, char **argv){

    
    if(argc < 2) //If Input file not entered
    {
        printRunCommand();
        return -1;
    }
    
    listAvailableCommands(); //list all available search options
    
    SearchFunction sfn;
    
    std::cout<<"Decrypting input file and parsing. Please wait for completion"<<std::endl;
    sfn.openAndParseData(argv[1]); // decrypt the text file and store in map in memory //pass by ref
    std::cout<<"End parsing"<<std::endl;
    
    createMap(); //pass by ref
    Searcher *s;
    
    bool allnumbers;    //to check if entered integers are all numbers
    bool exitcmd = false; // command 'exit' has not been entered till now
    
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
                sfn.search(tosearch,s);
        }
        
        
    }
    s=NULL;
    delete s;
    freemap();
    
    
    
    
}



