#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<boost/algorithm/searching/boyer_moore.hpp>
#include<string>
#include<time.h>
#include<map>


using namespace std;

typedef void (*fn_ptr)(vector <int>, map<int,vector< int > >, int s);


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
void printMatrix(vector< vector<int> > matrix){
    
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void listAvailableCommands(){

    cout<<endl<<"Available Commands are: "<<endl;
    cout<<endl;
    cout<<"1. searchSequence "<<endl<<"2. searchUnordered "<<endl<<"3. searchMaxMatch "<<endl<<"4. exit "<<endl;
    cout<<endl;
    cout<<"usage example: searchSequence 1 2 3"<<endl;
}
/*
void searchSequence(vector<int> tosearch,vector< vector <int> > matrix){

	cout<<"Need to search sequence: ";
	for(int i=0;i<tosearch.size();i++)
			cout<<tosearch[i]<<" ";
	cout<<endl;
    cout<<"Matrix to be searched: "<<endl;
    printMatrix(matrix);
    bool found = false;
    clock_t start = clock() ;
    
    for(int i=0;i<matrix.size();i++){
       
        if(boost::algorithm::boyer_moore_search(matrix[i].begin(), matrix[i].end(),tosearch.begin(), tosearch.end()).first != matrix[i].end()){
                    cout<<"Sequence found in row: "<<i+1<<endl; //Assuming row ordering starts from 1
                    found = true;
            }
    }
    
    clock_t end  = clock() ;
    
    if(!found)
        cout<<"Sequence not found in matrix"<<endl;
    
    float time = (float) (end - start) / CLOCKS_PER_SEC ;
    cout<<"Searching Time: "<<time<<" seconds"<<endl;

}

void searchUnordered(vector<int> tosearch,vector< vector <int> > matrix){

	cout<<"Need to search unordered: ";
	for(int i=0;i<tosearch.size();i++)
			cout<<tosearch[i]<<" ";
	cout<<endl;
    bool found = false;
    cout<<"Matrix to be searched: "<<endl;
    printMatrix(matrix);
    int len = tosearch.size();
    clock_t start = clock() ;
    
    for(int i=0;i<matrix.size();i++){
        int count=0;
        for(int j=0;j<tosearch.size();j++){
            vector<int>:: iterator pos = find(matrix[i].begin(), matrix[i].end(), tosearch[j]);
            if( pos != (matrix[i].end())){
                ++count;
                matrix[i].erase(pos);
            }
           
        
        }
        if(count == tosearch.size()){
            cout<<"Sequence found in row: "<<i+1<<endl; //Assuming row ordering starts from 1
            found = true;
        }
    }
    clock_t end  = clock() ;

    
    if(!found)
        cout<<"Numbers not found in matrix"<<endl;
	
    float time = (float) (end - start) / CLOCKS_PER_SEC ;
    cout<<"Searching Time: "<<time<<" seconds"<<endl;

}

void searchMaxMatch(vector<int> tosearch,vector< vector <int> > matrix){

	cout<<"Need to search maximum matching row for: ";
    
	for(int i=0;i<tosearch.size();i++)
			cout<<tosearch[i]<<" ";
    
	cout<<endl;
    
    cout<<"Matrix to be searched: "<<endl;
    printMatrix(matrix);
    int max = 0;
    vector<int> rownumbers;
    
    clock_t start = clock() ;

    for(int i=0;i<matrix.size();i++){
        int count=0;
        for(int j=0;j<tosearch.size();j++){
            vector<int>:: iterator pos = find(matrix[i].begin(), matrix[i].end(), tosearch[j]);
            
            if(pos != (matrix[i].end())){
                ++count;
                matrix[i].erase(pos);
            }
            
            
        }
        if(count > max){
            max = count;
            rownumbers.clear();
            rownumbers.push_back(i+1);
        }
        else if(count > 0 && count == max){
            rownumbers.push_back(i+1);
        }
    }
    clock_t end  = clock() ;

    if(rownumbers.size()==0)
        cout<<"Match not found in matrix"<<endl;
    else
    {
        cout<<"Maximum matches found in rows: ";
        for(int i = 0;i<rownumbers.size();i++)
            cout<<rownumbers[i]<<" ";
        cout<<endl;
    }

    float time = (float) (end - start) / CLOCKS_PER_SEC ;
    cout<<"Searching Time: "<<time<<" seconds"<<endl;

}*/
void printRunCommand(){
    cout<<endl<<"Please specify input file name"<<endl;
    cout<<endl<<"Run as ./search.o test.txt"<<endl;
}


vector< vector<int> > openAndParseData(char **argv,vector< vector<int> > &matrix ){
    
    ifstream input_file;
    string rawdata,parsed;
    input_file.open(argv[1]); //opening the input file
    
    if(input_file.is_open()){
        
        while(getline(input_file,rawdata)){
            
            parsed = decrypt(rawdata); //decrypting the data
            vector<int> row;
            istringstream iss(parsed);
            for(string s; iss >> s;){
                int x=0;
                stringstream ss(s);
                ss >> x;
                row.push_back(x); //getting values
            }
            matrix.push_back(row); // storing in matrix
        }
    }
    
    input_file.close();
    
    return matrix;
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

void searchSequence(vector<int> tosearch, map<int,vector< int > > m1,int s){
    
    
}
                    
void searchUnordered(vector<int> tosearch, map<int,vector< int > > m1,int s){
    
    int len = tosearch.size();
    cout<<"Searching Unordered "<<endl;
    clock_t start = clock() ;

    for(int i=0;i<s;i++){
        bool found = true;
        for(int j=0;j<len;j++){
            
            auto it = findcp (m1[tosearch[j]].begin(), m1[tosearch[j]].end(),i);
           
            if( it == m1[tosearch[j]].end()){
                found = false;
                break;
            }
            else{
               m1[tosearch[j]].erase(it);
            }
            
            
        }
        if(found)
            cout<<"Numbers found in row: "<<i+1<<endl;
    }    
    
    clock_t end = clock() ;
    float time = (float) (end - start) / CLOCKS_PER_SEC ;
    cout<<"Searching Time: "<<time<<" seconds"<<endl;

}

void searchMaxMatch(vector<int> tosearch, map<int,vector< int > > m1,int s){
    
    
}
                    
void add_function_mappings(map<string,fn_ptr> &fnMap){
    fnMap["searchSequence"] = searchSequence;
    fnMap["searchUnordered"] = searchUnordered;
    fnMap["searchMaxMatch"] = searchMaxMatch;
    
}

int main(int argc, char **argv){

	vector< vector<int> > matrix; //matrix representation of text file
    bool allnumbers; // validates if entered input has numbers only
    bool exitcmd = false; //has exit command been entered
    map<string, fn_ptr> fnMap; // map holding function pointers
    
    map<int,vector< int > > m1;
    
	if(argc < 2)
	{	
        printRunCommand(); //Input file not entered
		return -1;
	}
    
	listAvailableCommands(); //list all available options
    
    cout<<"Start parsing"<<endl;
    openAndParseData(argv,matrix); // decrypt the text file and store in matrix
    cout<<"End parsing"<<endl;

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            
            cout<<i<<" "<<j<<" "<<endl;
            if(m1.count(matrix[i][j]) == 0){
                
                vector< int > v;
                v.push_back(i);
                m1[matrix[i][j]] = v;
            }
            else
            {
                vector <int > v = m1[matrix[i][j]];
                v.push_back(i);
                m1[matrix[i][j]] = v;
            }
            
        }
       
        
    }
    cout<<"End Assignment"<<endl;
    add_function_mappings(fnMap); //map strings to their functions
    
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
            cerr<<endl<<"ERROR: Command Not Found"<<endl; //invalid command
        else
            fnMap[cmd](tosearch,m1,matrix.size()); //call the function
        
		
	}
}
