#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>


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
cout<<endl;
cout<<"Available Commands are: "<<endl;
cout<<endl;
cout<<"1. searchSequence "<<endl<<"2. searchUnordered "<<endl<<"3. searchMaxMatch "<<endl<<"4. exit "<<endl;
cout<<endl;
cout<<"usage example: searchSequence 1 2 3"<<endl;

}
void searchSequence(vector<int> tosearch){

	cout<<"Need to search sequence: ";
	for(int i=0;i<tosearch.size();i++)
			cout<<tosearch[i]<<" ";
	cout<<endl;
	cout<<"Yet to be implemented"<<endl;

}
void searchUnordered(vector<int> tosearch){

	cout<<"Need to search unordered: ";
	for(int i=0;i<tosearch.size();i++)
			cout<<tosearch[i]<<" ";
	cout<<endl;
	cout<<"Yet to be implemented"<<endl;

}
void searchMaxMatch(vector<int> tosearch){

	cout<<"Need to search maximum matching row for: ";
	for(int i=0;i<tosearch.size();i++)
			cout<<tosearch[i]<<" ";
	cout<<endl;
	cout<<"Yet to be implemented"<<endl;

}
int main(int argc, char **argv){

	vector<vector<int>> matrix;

	if(argc < 2)
	{	
		cout<<"Please specify input file name"<<endl;
		return -1;
	}
	listAvailableCommands();
	ifstream input_file;
	ofstream ofile("decrypted.txt");
	input_file.open(argv[1]);
	string rawdata;
	int row_count = 0, col_count = 0;
	string parsed;
	if(input_file.is_open()){
	

		while(getline(input_file,rawdata)){	
			parsed = decrypt(rawdata);
			//ofile<<parsed<<endl;
			vector<int> row;
			istringstream iss(parsed);
			for(string s; iss >> s;){
				int x=0;
				stringstream ss(s);
				ss >> x;
				row.push_back(x);			
			}
			matrix.push_back(row);
		}
	}
	
	/*for(int i=0;i<matrix.size();i++){
		for(int j=0;j<matrix[i].size();j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}*/

	bool exitcmd = false;
	while(!exitcmd){
		string cmd,line;
		vector<int> tosearch;
		cout<<"Enter command: "<<endl;
		getline(cin,line);
	
		int found=0,pos=0;
		bool first = false;
		while((found = line.find_first_of(' ',pos))!= string::npos){

			if(!first){
				cmd = line.substr(pos,found - pos);
				first = true;

			}
			else
			{	
				stringstream tmp(line.substr(pos,found - pos));
				int x = 0;
				tmp >> x;
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
		if(tosearch.size()==0)
		{
			cout<<"Please input integers to search"<<endl;
			listAvailableCommands();
		}
		else
		{
			if(cmd == "searchSequence")
				searchSequence(tosearch);
			else if(cmd == "searchUnordered")
				searchUnordered(tosearch);
			else if(cmd =="searchMaxMatch")
				searchMaxMatch(tosearch);
			else if(cmd =="exit"){
				exitcmd = true;
		
			else{
			cout<<"Command Not Found"<<endl;
			listAvailableCommands();
			}
		}
	}
}
