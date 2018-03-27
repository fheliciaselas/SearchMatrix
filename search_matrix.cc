#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>

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
void printMatrix(vector< vector<int> > matrix){
    
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
void listAvailableCommands(){
    cout<<endl;
    cout<<endl<<"Available Commands are: "<<endl;
    cout<<endl;
    cout<<"1. searchSequence "<<endl<<"2. searchUnordered "<<endl<<"3. searchMaxMatch "<<endl<<"4. exit "<<endl;
    cout<<endl;
    cout<<"usage example: searchSequence 1 2 3"<<endl;
}

void searchSequence(vector<int> tosearch,vector< vector <int> > matrix){

	cout<<"Need to search sequence: ";
	for(int i=0;i<tosearch.size();i++)
			cout<<tosearch[i]<<" ";
	cout<<endl;
    cout<<"Matrix to be searched: "<<endl;
    printMatrix(matrix);
    bool found = false;
    for(int i=0;i<matrix.size();i++){
       
        if(search(matrix[i].begin(), matrix[i].end(), tosearch.begin(), tosearch.end()) != (matrix[i].end())){
                    cout<<"Sequence found in row: "<<i<<endl; //Assuming row ordering starts from 0
                    found = true;
            }
    }
    if(!found)
        cout<<"Sequence not found in matrix"<<endl;

}

void searchUnordered(vector<int> tosearch,vector< vector <int> > matrix){

	cout<<"Need to search unordered: ";
	for(int i=0;i<tosearch.size();i++)
			cout<<tosearch[i]<<" ";
	cout<<endl;
    bool found = false;
    cout<<"Matrix to be searched: "<<endl;
    printMatrix(matrix);
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
            cout<<"Sequence found in row: "<<i<<endl; //Assuming row ordering starts from 0
            found = true;
        }
    }
    
    if(!found)
        cout<<"Numbers not found in matrix"<<endl;
	
}

void searchMaxMatch(vector<int> tosearch,vector< vector <int> > matrix){

	cout<<"Need to search maximum matching row for: ";
    
	for(int i=0;i<tosearch.size();i++)
			cout<<tosearch[i]<<" ";
    
	cout<<endl;
    
    cout<<"Matrix to be searched: "<<endl;
    printMatrix(matrix);
    int max = 0,maxrow = -1;
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
            maxrow = i;
        }
    }
    
    if(maxrow > -1)
        cout<<"Maximum matches found in row: "<<maxrow<<endl;
    else
        cout<<"Match not found in matrix"<<endl;


}
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
            
            parsed = decrypt(rawdata); //decrypting the data row by row
            vector<int> row;
            istringstream iss(parsed);
            for(string s; iss >> s;){
                int x=0;
                stringstream ss(s);
                ss >> x;
                    row.push_back(x); //getting values of the row
            }
            matrix.push_back(row); // storing in matrix row by row
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
                if(x==0 && s != "0")
                {
                    cout<<endl<<"Invalid input"<<endl;
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


int main(int argc, char **argv){

	vector< vector<int> > matrix;
    bool allnumbers;
    bool exitcmd = false; //has exit command been entered
    string cmd;
    
	if(argc < 2)
	{	
        printRunCommand();
		return -1;
	}
    
	listAvailableCommands();
	
    openAndParseData(argv,matrix);
	
    
    
    while(!exitcmd){
        
        string cmd,line;
        vector<int> tosearch;
        
        cout<<endl<<"Enter command: "<<endl;
        getline(cin,line);
        allnumbers = true;
        parseCommandInput(cmd,tosearch,line,allnumbers);
	
        // validateInput(cmd,tosearch); -- To Do. validate if integer.
        if(!allnumbers){
            cout<<"Please enter only integers"<<endl;
        }
        else if(tosearch.size()==0 && cmd !="exit")
        {
            cout<<"Please input integers to search"<<endl;
            listAvailableCommands();
        }
        else{
            if(cmd =="exit"){
                exitcmd = true;
            }
            else if(cmd == "searchSequence")
                searchSequence(tosearch,matrix); //call appropriate function
			else if(cmd =="searchMaxMatch")
				searchMaxMatch(tosearch,matrix); //call appropriate function
            else if(cmd == "searchUnordered")
                searchUnordered(tosearch,matrix); //call appropriate function
			else{
                cout<<endl<<"ERROR: Command Not Found"<<endl; //invalid commands
                listAvailableCommands(); //show available commands
			}
        }
		
	}
}
