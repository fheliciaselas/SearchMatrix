#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;


int main(){
    
    
    int m,n;
    string filename;
    cout<<"Enter x and y dimensions of matrix: "<<endl;
    cin>>m>>n;
    cout<<"Enter output filename"<<endl;
    cin>>filename;
    
    ofstream outfile(filename);
    
    for (int i=0;i <m; i++) {
        for(int j=0;j<n;j++){
            outfile <<rand() % 1000<<" ";
        }
        outfile<<endl;
    }
    
    
    
}
