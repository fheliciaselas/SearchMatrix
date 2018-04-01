#include<iostream>
#include<fstream>
#include <string>
using namespace std;

string encrypt(string raw_text)
{
	const char key = 'N';
	string output = raw_text;
	int len = output.size();
	for(int i=0;i<len;i++){
		output[i] = raw_text[i] ^ key;
	}

	return output;
}

int main(int argc,char** argv){

	if(argc<2)
	{
		return -1;		
	}
	
	string rawdata;
	ifstream input_file;
	string fname = argv[1];
	input_file.open(fname);

	ofstream outfile("test.txt");
	if(input_file.is_open()){

		while(getline(input_file,rawdata)){
			
			string enc_string = encrypt(rawdata);
			outfile<<enc_string<<endl;
		}
	} 

	input_file.close();
	outfile.close();
	


}
