#include<iostream>
#include<fstream>
#include <string>

std::string encrypt(std::string raw_text)
{
	const char key = 'N';
    std::string output = raw_text;
	int len = output.size();
	for(int i=0;i<len;i++){
		output[i] = raw_text[i] ^ key;
	}

	return output;
}

int main(int argc,char** argv){

	if(argc<2)
	{
        std::cout<<"Filename not specified. Run as ./encrypt_text inputfilename."<<std::endl;
		return -1;		
	}
	
	std::string rawdata;
	std::ifstream input_file;
	std::string fname = argv[1];
	input_file.open(fname);

    std::string ofile_name = "../inputfile/encrypted.txt";
	std::ofstream outfile(ofile_name);
	if(input_file.is_open()){

		while(getline(input_file,rawdata)){
			
			std::string enc_string = encrypt(rawdata);
			outfile<<enc_string<<std::endl;
		}
        std::cout<<"Output file "<<ofile_name<<" created"<<std::endl;

        
	}
    else
        std::cout<<"File Not found"<<std::endl;

	input_file.close();
	outfile.close();
	


}
