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

using namespace std;

string decrypt(string raw_text)
{
    const char key = 'N';
    string output = raw_text;
    int len = output.size();
    for(int i=0;i<len;i++){
        output[i] = raw_text[i] ^ key;
    }
    
    return output;
}

void listAvailableCommands(){
    
    cout<<endl<<"Available Commands are: "<<endl;
    cout<<endl;
    cout<<"1. searchSequence "<<endl<<"2. searchUnordered "<<endl<<"3. searchMaxMatch "<<endl<<"4. exit "<<endl<<endl;
    cout<<"usage example: searchSequence 1 2 3"<<endl;
}

void printRunCommand(){
    cout<<endl<<"Please specify input file name"<<endl;
    cout<<endl<<"Run as ./search.o test.txt"<<endl;
}

void  openAndParseData(char **argv, unordered_map< int, unordered_map <int,int > >  &elementCountMap, vector < vector <int > > &matrix ){
    
    ifstream input_file;
    string rawdata,parsed;
    
    input_file.open(argv[1]); //opening the input file
    
    int row_count=0;
    
    if(input_file.is_open()){
        
        while(getline(input_file,rawdata)){
            
            unordered_map<int,int> temp;
            vector <int> row;
            
            parsed = decrypt(rawdata); //decrypting each row in the data
            istringstream iss(parsed);
            
            for(string s; iss >> s;){
                
                int x=0;
                
                stringstream ss(s);
                ss >> x; //write string to integer
                
                row.push_back(x); // push to vector 'row'
                
                if(temp.count(x)==0){  //check if element not present
                    temp[x] =1; // then set count to 1
                }
                else{
                    temp[x] = temp[x]+1; // increment count of element
                }
                
            }
            elementCountMap[row_count] = temp; // map of count of elements added to key = row number
            matrix.push_back(row); // add the 'row' vector to the matrix
            row_count++;
        }
    }
    
    input_file.close();
}

void parseCommandInput(string &cmd,vector<int> &tosearch,string line, bool &allnumbers){
    
    int found=0,pos=0;
    bool first = false;
    while((found = line.find_first_of(' ',pos))!= string::npos){
        
        string s = line.substr(pos,found - pos);
        if(!first){
            cmd = s;
            first = true;
        }
        else
        {
            stringstream tmp(s);
            int x = 0;
            tmp >> x;
            if(to_string(x) != s)
            {
                cerr<<endl<<"ERROR: Invalid input"<<endl;
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
        stringstream tmp(line.substr(pos));
        int x = 0;
        tmp >> x;
        tosearch.push_back(x);
    }
    
}
Searcher* getSearchObject(string cmd, vector< vector<int > > matrix, unordered_map< int, unordered_map <int,int > >  elementCountMap){
    
    if(cmd =="searchSequence")
        return new SequenceSearcher(matrix,elementCountMap);
    else if(cmd == "searchUnordered")
        return new UnorderedSearcher(matrix,elementCountMap);
    else if(cmd == "searchMaxMatch")
        return new MaxMatchSearcher(matrix,elementCountMap);
    else
        return NULL;
}
int main(int argc, char **argv){

    vector< vector<int > > matrix;  // 2D representation of matrix
    unordered_map <int,unordered_map<int,int> > elementCountMap; //count of each element in a row in the matrix
    
    bool allnumbers;    //to check if entered integers are all numbers
    bool exitcmd = false; // command 'exit' has not been entered till now
    
    if(argc < 2) //If Input file not entered
    {
        printRunCommand();
        return -1;
    }
    
    listAvailableCommands(); //list all available search options
    
    cout<<"Decrypting input file and parsing. Please wait for completion"<<endl;
    openAndParseData(argv, elementCountMap,matrix); // decrypt the text file and store in map in memory
    cout<<"End parsing"<<endl;
    
    Searcher *s;
   
    while(!exitcmd){
        
        string cmd,line;
        vector<int> tosearch; // sequence or numbers to be searched
        
        cout<<endl<<"Enter command: "<<endl;
        getline(cin,line);
        allnumbers = true;
        parseCommandInput(cmd,tosearch,line,allnumbers); //parse line to seperate command from numbers.
        //also check if all are integers
        
        if(!allnumbers)
            cerr<<"ERROR : Please enter only integers"<<endl;
        else if(tosearch.size()==0 && cmd !="exit")
            cerr<<endl<<"ERROR: Please input integers to search"<<endl;
        else if(cmd =="exit")
            exitcmd = true; //exit program
        /*else if(fnMap[cmd]== NULL)
            cerr<<endl<<"ERROR: Command "<<cmd<<" Not Found"<<endl; //invalid command
        else
            fnMap[cmd](tosearch,m1); //call the function
         */
         
        else
        {
            s = getSearchObject(cmd,matrix,elementCountMap);
            if(s==NULL)
                cout<<"Invalid Command"<<endl;
            else
                s->search(tosearch);
        }
        
    }
}



