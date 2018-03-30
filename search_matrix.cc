#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<boost/algorithm/searching/knuth_morris_pratt.hpp>
#include<string>
#include<time.h>
#include<map>


using namespace std;

typedef void (*fn_ptr)(vector <int>,map< int, map<int,int > > );
vector< vector<int > > matrix; // 2D matrix representation of text file

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
    cout<<"1. searchSequence "<<endl<<"2. searchUnordered "<<endl<<"3. searchMaxMatch "<<endl<<"4. exit "<<endl;
    cout<<endl;
    cout<<"usage example: searchSequence 1 2 3"<<endl;
}

void printRunCommand(){
    cout<<endl<<"Please specify input file name"<<endl;
    cout<<endl<<"Run as ./search.o test.txt"<<endl;
}

void  openAndParseData(char **argv, map< int, map <int,int > >  &m1, vector < vector <int > > &matrix ){
    
    ifstream input_file;
    string rawdata,parsed;
    input_file.open(argv[1]); //opening the input file
    int row_count=0;
    if(input_file.is_open()){
        
        while(getline(input_file,rawdata)){
            
            parsed = decrypt(rawdata); //decrypting the data
            map<int,int> temp;
            vector <int> order;
            istringstream iss(parsed);
            int col_count=0;
            for(string s; iss >> s;){
                int x=0;
                stringstream ss(s);
                ss >> x;
                order.push_back(x);
    
                if(temp.count(x)==0){
                    temp[x] =1;
                }
                else{
                    temp[x] = temp[x]+1;
                }
                
            }
            m1[row_count] = temp;
            matrix.push_back(order);
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

void searchSequence(vector<int> tosearch, map< int, map<int,int > > m1){
    
   // bool found = false;
    int rows = matrix.size();
    vector<int> rowsfound;

    clock_t start = clock() ;

    
    for(int i=0;i<rows;i++){
        
        if(boost::algorithm::knuth_morris_pratt_search(matrix[i].begin(), matrix[i].end(),tosearch.begin(), tosearch.end()).first != matrix[i].end()){
            rowsfound.push_back(i+1); //Assuming row ordering starts from 1
            
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
                    
void searchUnordered(vector<int> tosearch, map< int, map<int,int > > m1){
    
    int len = tosearch.size();
    vector<int> rowsfound;
    cout<<"Searching Unordered "<<endl;
    
    clock_t start = clock() ;

    int s = m1.size(); //rows
    
    for(int i=0;i<s;i++){ //for each row
        bool found = true;
        
        for(int j=0;j<len;j++){
            int key = tosearch[j];
            if(m1[i].count(key) == 0 || m1[i][key] == 0){
                found = false;
                break;
            }
            else
                m1[i][key] -= 1;
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

void searchMaxMatch(vector<int> tosearch, map< int, map<int,int > > m1){
    
    int len = tosearch.size();
    vector<int> rowsfound;
    cout<<"Searching Max Match rows "<<endl;
    
    clock_t start = clock() ;
    
    int s = m1.size(); //rows
    int maxrow = -1, max = 0;
    for(int i=0;i<s;i++){ //for each row
        int count = 0;
        for(int j=0;j<len;j++){
            if(m1[i][tosearch[j]] > 0)
                ++count;
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
                    
void add_function_mappings(map<string,fn_ptr> &fnMap){
    fnMap["searchSequence"] = searchSequence;
    fnMap["searchUnordered"] = searchUnordered;
    fnMap["searchMaxMatch"] = searchMaxMatch;
    
}

void createSearchCount(map<int, int > &searchCount,vector<int> tosearch){
    
    int len = tosearch.size();
    for(int i=0;i<len;i++){
        if(searchCount.count(tosearch[i])==0)
            searchCount[tosearch[i]]=1;
        else
            searchCount[tosearch[i]] = searchCount[tosearch[i]]+1;
    }
}

int main(int argc, char **argv){

	
    bool allnumbers; // validates if entered input has numbers only
    bool exitcmd = false; //has exit command been entered
    map<string, fn_ptr> fnMap; // map holding function pointers
    
    map <int,map<int,int> > m1;
    
	if(argc < 2)
	{	
        printRunCommand(); //Input file not entered
		return -1;
	}
    
	listAvailableCommands(); //list all available options
    
    cout<<"Parsing Input file after decrypting. Wait for completion"<<endl;
    openAndParseData(argv, m1,matrix); // decrypt the text file and store in map
    cout<<"End parsing"<<endl;

    add_function_mappings(fnMap); //map user string to function
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
        else if(fnMap[cmd]== NULL)
            cerr<<endl<<"ERROR: Command "<<cmd<<" Not Found"<<endl; //invalid command
        else
            fnMap[cmd](tosearch,m1); //call the function
        
		
	}
}
