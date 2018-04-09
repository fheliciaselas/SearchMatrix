#include<iostream>
#include<vector>
#include<string.h>
#include "../code/SearchFunction.h"
#include "../code/SequenceSearcher.h"
#include "../code/UnorderedSearcher.h"
#include "../code/MaxMatchSearcher.h"
#include "../code/Searcher.h"

void test(SearchFunction&);
int main(){
    
    std::cout<<"Benchmarking the Search Functions"<<std::endl;
    
    SearchFunction sf;
    
    test(sf);
}

void benchmark_speed(std::vector<int> tosearch,SearchFunction &sf, Searcher *sq,std::string dimensions,bool random,int len){
    
    double time=0;
    
    for(int i=0;i<1000;i++){
        double c=0;
        if(random){
            tosearch.clear();
            for(int j=0;j<len;j++){
                int n = rand() % 1000;
                //std::cout<<n<<" ";
                tosearch.push_back(n);
            }
        }
        c= sf.benchmark_search(tosearch,sq);
        //std::cout<<std::endl;
        
        time +=c;
    }
    std::cout<<"Time for "<<dimensions<<" matrix: "<<(time/1000)*1000000<<" micro seconds"<<std::endl;
}

void benchmarkMatrix(SearchFunction &sf, Searcher *s, std::vector<int> &tosearch,std::string dimensions, bool random,int len){
    
    std::string str = dimensions+"encrypted.txt";
    char *file = strdup(str.c_str());
    sf.openAndParseData(file);
    benchmark_speed(tosearch,sf,s,dimensions,random,len);
}

void test(SearchFunction &sf){
    
    Searcher *sq = new SequenceSearcher();
    Searcher *su = new UnorderedSearcher();
    Searcher *sm = new MaxMatchSearcher();

    std:: string dimensions="10by10";
 
    std::cout<<"Benchmarking Sequence Search for "<<dimensions<<" matrix: "<<std::endl;
    std::vector<int> tosearch = {967,672,393,336,485,745,228,91,194,357 };
    benchmarkMatrix(sf,sq,tosearch,dimensions,true,10);
    
    
    std::cout<<"Benchmarking Unordered Search for "<<dimensions<<" matrix: "<<std::endl;
    tosearch.clear();
   
    benchmarkMatrix(sf,su,tosearch,dimensions,true,10);
    
    std::cout<<"Benchmarking MaxMatch Search for "<<dimensions<<" matrix: "<<std::endl;
   // tosearch = {485,745,228,967,672,393,336,91,194,357 };
    benchmarkMatrix(sf,sm,tosearch,dimensions,true,10);
    
    std::cout<<std::endl;
    
    dimensions ="100by100";
    std::cout<<"Benchmarking Sequence Search for "<<dimensions<<" matrix: "<<std::endl;
    tosearch = { 58,284,614,556,10,948,243,755,162,957,744,62,286,957,785,495,857,399,177, 236 };
    benchmarkMatrix(sf,sq,tosearch,dimensions,true,20);
    
    std::cout<<"Benchmarking Unordered Search for "<<dimensions<<" matrix: "<<std::endl;
    benchmarkMatrix(sf,su,tosearch,dimensions,true,20);
    std::cout<<"Benchmarking MaxMatch Search Found case for "<<dimensions<<" matrix: "<<std::endl;
    benchmarkMatrix(sf,sm,tosearch,dimensions,true,20);
    
    std::cout<<std::endl;

    dimensions ="100by1000";
    std::cout<<"Benchmarking Sequence Search for "<<dimensions<<" matrix: "<<std::endl;
    tosearch = { 560,430,929,323,803,652,876,819,699,904,157,935,382,736,291,142,125,576,285, 423  };
    benchmarkMatrix(sf,sq,tosearch,dimensions,true,20);
    
    std::cout<<"Benchmarking Unordered Search for "<<dimensions<<" matrix: "<<std::endl;
   benchmarkMatrix(sf,su,tosearch,dimensions,true,20);
    std::cout<<"Benchmarking MaxMatch Search for "<<dimensions<<" matrix: "<<std::endl;
    benchmarkMatrix(sf,sm,tosearch,dimensions,true,20);
    
    std::cout<<std::endl;
    
    dimensions ="1000by1000";
    
    std::cout<<"Benchmarking Sequence Search for "<<dimensions<<" matrix: "<<std::endl;
    tosearch = {820,237,90,549,199,917,688,241,879,628,270,106,470,904,653,344,616,90,705,745};
    benchmarkMatrix(sf,sq,tosearch,dimensions,true,20);
    std::cout<<"Benchmarking Unordered Search for "<<dimensions<<" matrix: "<<std::endl;
    benchmarkMatrix(sf,su,tosearch,dimensions,true,20);
    std::cout<<"Benchmarking MaxMatch Search for "<<dimensions<<" matrix: "<<std::endl;
    benchmarkMatrix(sf,sm,tosearch,dimensions,true,20);
    
    
    delete sq;
    delete su;
    delete sm;
}





