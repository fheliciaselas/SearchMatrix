#include<iostream>
#include<vector>
#include "../code/SearchFunction.h"
#include "../code/SequenceSearcher.h"
#include "../code/UnorderedSearcher.h"
#include "../code/MaxMatchSearcher.h"
#include "../code/Searcher.h"

void test(SearchFunction&);
int main(){
    
    std::cout<<"Benchmarking the Search Functions"<<std::endl;
    
    SearchFunction sf;
    
    /* input matrix
     1 2 3 4 5 6 7 8 9 0
     5 6 1 4 5 6 7 5 4 1
     1 1 1 3 3 3 14 1 10 0
     1 2 12 2 14 1 19 1 1 7
     1 7 8 9 3 14 1 10 1 7
     */
    
    test(sf);
}

void benchmark_speed(std::vector<int> tosearch,SearchFunction &sf, Searcher *sq,std::string dimensions){
    
    float time=0;
    for(int i=0;i<10000;i++){
        time += sf.benchmark_search(tosearch,sq);
    }
    std::cout<<"Time for "<<dimensions<<" matrix: "<<time/10000<<std::endl;
}

void benchmarkMatrix(SearchFunction &sf, Searcher *s, std::vector<int> &tosearch,std::string dimensions){
    
    std::string str = dimensions+"encrypted.txt";
    char *file = strdup(str.c_str());
    sf.openAndParseData(file);
    benchmark_speed(tosearch,sf,s,dimensions);
}

void test(SearchFunction &sf){
    
    Searcher *sq = new SequenceSearcher();
    Searcher *su = new UnorderedSearcher();
    Searcher *sm = new MaxMatchSearcher();

    std:: string dimensions="10by10";
 
    std::cout<<"Benchmarking Sequence Search Found case for "<<dimensions<<" matrix: "<<std::endl;
    std::vector<int> tosearch = {967,672,393,336,485,745,228,91,194,357 };
    benchmarkMatrix(sf,sq,tosearch,dimensions);
    
    
    std::cout<<"Benchmarking Unordered Search Found case for "<<dimensions<<" matrix: "<<std::endl;
    tosearch = {485,745,228,967,672,393,336,91,194,357 };
    benchmarkMatrix(sf,su,tosearch,dimensions);
    
    std::cout<<"Benchmarking MaxMatch Search Found case for "<<dimensions<<" matrix: "<<std::endl;
    tosearch = {485,745,228,967,672,393,336,91,194,357 };
    benchmarkMatrix(sf,sm,tosearch,dimensions);
    
    std::cout<<std::endl;
    
    dimensions ="100by100";
    std::cout<<"Benchmarking Sequence Search Found case for "<<dimensions<<" matrix: "<<std::endl;
    tosearch = { 58,284,614,556,10,948,243,755,162,957,744,62,286,957,785,495,857,399,177, 236 };
    benchmarkMatrix(sf,sq,tosearch,dimensions);
    
    std::cout<<"Benchmarking Unordered Search Found case for "<<dimensions<<" matrix: "<<std::endl;
    tosearch = { 58,284,614,556,10,138,980,705,415,833,882,636,806,178,404,174,97,869,259,561};
    benchmarkMatrix(sf,su,tosearch,dimensions);
    std::cout<<"Benchmarking MaxMatch Search Found case for "<<dimensions<<" matrix: "<<std::endl;
    benchmarkMatrix(sf,sm,tosearch,dimensions);
    
    std::cout<<std::endl;

    dimensions ="100by1000";
    std::cout<<"Benchmarking Sequence Search Found case for "<<dimensions<<" matrix: "<<std::endl;
    tosearch = { 560,430,929,323,803,652,876,819,699,904,157,935,382,736,291,142,125,576,285, 423  };
    benchmarkMatrix(sf,sq,tosearch,dimensions);
    
    std::cout<<"Benchmarking Unordered Search Found case for "<<dimensions<<" matrix: "<<std::endl;
    tosearch = {560,699,904,157,935,382,430,929,323,803,736,291,125,423,576,285,142,652,876  };
    benchmarkMatrix(sf,su,tosearch,dimensions);
    std::cout<<"Benchmarking MaxMatch Search Found case for "<<dimensions<<" matrix: "<<std::endl;
    benchmarkMatrix(sf,sm,tosearch,dimensions);
    
    std::cout<<std::endl;

    dimensions ="1000by100";
    
    std::cout<<"Benchmarking Sequence Search Found case for "<<dimensions<<" matrix: "<<std::endl;
    tosearch = { 575, 794, 758, 99, 737, 390, 594, 877, 103, 241, 86, 651, 275, 39, 417, 158, 352, 241, 925, 110 };
    benchmarkMatrix(sf,sq,tosearch,dimensions);
    
    std::cout<<"Benchmarking Unordered Search Found case for "<<dimensions<<" matrix: "<<std::endl;
    tosearch = {758, 241, 925, 99, 651, 275, 39, 737, 575, 794, 390, 594, 241, 877, 103, 352, 86, 417, 158, 110 };
    benchmarkMatrix(sf,su,tosearch,dimensions);
    std::cout<<"Benchmarking MaxMatch Search Found case for "<<dimensions<<" matrix: "<<std::endl;
    benchmarkMatrix(sf,sm,tosearch,dimensions);
    
    std::cout<<std::endl;
    
    dimensions ="1000by1000";
    
    std::cout<<"Benchmarking Sequence Search Found case for "<<dimensions<<" matrix: "<<std::endl;
    tosearch = {820,237,90,549,199,917,688,241,879,628,270,106,470,904,653,344,616,90,705,745};
    benchmarkMatrix(sf,sq,tosearch,dimensions);
    
    std::cout<<"Benchmarking Unordered Search Found case for "<<dimensions<<" matrix: "<<std::endl;
    tosearch = {820,549,199,237,917,688,879,628,106,90,705,745,470,653,344,616,904,270,241,90};
    benchmarkMatrix(sf,su,tosearch,dimensions);
    std::cout<<"Benchmarking MaxMatch Search Found case for "<<dimensions<<" matrix: "<<std::endl;
    benchmarkMatrix(sf,sm,tosearch,dimensions);
    
    
    delete sq;
    delete su;
    delete sm;
}





