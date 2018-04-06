#include<iostream>
#include<vector>
#include<string.h>
#include "../code/SearchFunction.h"
#include "../code/SequenceSearcher.h"
#include "../code/UnorderedSearcher.h"
#include "../code/MaxMatchSearcher.h"
#include "../code/Searcher.h"

void testSequence(SearchFunction&);
void testUnordered(SearchFunction&);
void testMaxMatch(SearchFunction&);
void printarr(std::vector<int> &arr);
void printResult(std::vector<int> &expected, std::vector<int> &result);
int main(){
    
    std::cout<<"Testing the Search Functions";
    
    SearchFunction sf;
    std::string str = "encrypted.txt";
    char *file = strdup(str.c_str());
    
    sf.openAndParseData(file);
    /* input matrix
     1 2 3 4 5 6 7 8 9 0
     5 6 1 4 5 6 7 5 4 1
     1 1 1 3 3 3 14 1 10 0
     1 2 12 2 14 1 19 1 1 7
     1 7 8 9 3 14 1 10 1 7
     */
    
    testSequence(sf);
    testUnordered(sf);
    testMaxMatch(sf);
}



void TestSeqInRow1(SearchFunction &sf, Searcher *sq){
    
    std::cout<<"Case 1: Sequence in Row 1"<<std::endl;
    std::vector<int> tosearch = {1,2,3,4};
    std::vector<int> expected = {1};
    std::vector<int> result = sf.search(tosearch,sq);
    printResult(expected,result);
}
void TestSeqInRow5(SearchFunction &sf, Searcher *sq){
    
    std::cout<<"Case 2: Sequence in row 5"<<std::endl;
    std::vector<int> tosearch = {14,1,10,1,7};
    std::vector<int> expected = {5};
    std::vector<int> result = sf.search(tosearch,sq);
    printResult(expected,result);
}
void TestSeqNotInMatrix(SearchFunction &sf, Searcher *sq){
    
    std::cout<<"Case 3: Sequence not in Matrix"<<std::endl;
    std::vector<int> tosearch = {14,1,9,8,6,2};
    std::vector<int> expected = {};
    std::vector<int> result = sf.search(tosearch,sq);
    printResult(expected,result);
}
void TestExactRepetitionSeqMatrix(SearchFunction &sf, Searcher *sq){
    
    std::cout<<"Case 4: Sequence with repetitions"<<std::endl;
    std::vector<int> tosearch = {1,1,1};
    std::vector<int> expected = {3};
    std::vector<int> result = sf.search(tosearch,sq);
    printResult(expected,result);
}
void TestSeqinAllRows(SearchFunction &sf, Searcher *sq){
    
    std::cout<<"Case 4: Sequence in all rows"<<std::endl;
    std::vector<int> tosearch = {1};
    std::vector<int> expected = {1,2,3,4,5};
    std::vector<int> result = sf.search(tosearch,sq);
    printResult(expected,result);
}
void testSequence(SearchFunction &sf){
    
    Searcher *sq = new SequenceSearcher();
    
    TestSeqInRow1(sf,sq);
    TestSeqInRow5(sf,sq);
    TestSeqNotInMatrix(sf,sq);
    TestExactRepetitionSeqMatrix(sf,sq);
    TestSeqinAllRows(sf,sq);
    
    delete sq;
}





//UnorderedSearch test cases

void TestUnordInRow1(SearchFunction &sf, Searcher *u){
    
    std::cout<<"Case 1: Numbers in Row 1"<<std::endl;
    std::vector<int> tosearch = {1,4,9,0};
    std::vector<int> expected = {1};
    std::vector<int> result = sf.search(tosearch,u);
    printResult(expected,result);
}
void TestUnordInRow5(SearchFunction &sf, Searcher *u){
    
    std::cout<<"Case 2: Numbers in row 5"<<std::endl;
    std::vector<int> tosearch = {14,1,10,7};
    std::vector<int> expected = {5};
    std::vector<int> result = sf.search(tosearch,u);
    printResult(expected,result);
}
void TestUnordNotInMatrix(SearchFunction &sf, Searcher *u){
    
    std::cout<<"Case 3: Numbers not in Matrix"<<std::endl;
    std::vector<int> tosearch = {14,1,9,8,6,2};
    std::vector<int> expected = {};
    std::vector<int> result = sf.search(tosearch,u);
    printResult(expected,result);
}
void TestExactRepetitionUnordMatrix(SearchFunction &sf, Searcher *u){
    
    std::cout<<"Case 4: Numbers with repetitions"<<std::endl;
    std::vector<int> tosearch = {1,1,1};
    std::vector<int> expected = {3,4,5};
    std::vector<int> result = sf.search(tosearch,u);
    printResult(expected,result);
}
void TestUnordinAllRows(SearchFunction &sf, Searcher *u){
    
    std::cout<<"Case 4: Numbers in all rows"<<std::endl;
    std::vector<int> tosearch = {1};
    std::vector<int> expected = {1,2,3,4,5};
    std::vector<int> result = sf.search(tosearch,u);
    printResult(expected,result);
}
void testUnordered(SearchFunction &sf){
    
    Searcher *u = new UnorderedSearcher();
    
    TestUnordInRow1(sf,u);
    TestUnordInRow5(sf,u);
    TestUnordNotInMatrix(sf,u);
    TestExactRepetitionUnordMatrix(sf,u);
    TestUnordinAllRows(sf,u);
    
    delete u;
}





//MaxMatch


void TestMaxMatchInRow1(SearchFunction &sf, Searcher *u){
    
    std::cout<<"Case 1: Numbers in Row 1"<<std::endl;
    std::vector<int> tosearch = {1,4,9,0};
    std::vector<int> expected = {1};
    std::vector<int> result = sf.search(tosearch,u);
    printResult(expected,result);
}
void TestMaxMatchInRow5(SearchFunction &sf, Searcher *u){
    
    std::cout<<"Case 2: Numbers in row 5"<<std::endl;
    std::vector<int> tosearch = {14,7,10,7};
    std::vector<int> expected = {5};
    std::vector<int> result = sf.search(tosearch,u);
    printResult(expected,result);
}
void TestMaxMatchNotInMatrix(SearchFunction &sf, Searcher *u){
    
    std::cout<<"Case 3: Numbers not in Matrix"<<std::endl;
    std::vector<int> tosearch = {99,199,909,888,676,652};
    std::vector<int> expected = {};
    std::vector<int> result = sf.search(tosearch,u);
    printResult(expected,result);
}
void TestExactRepetitionMaxMatchMatrix(SearchFunction &sf, Searcher *u){
    
    std::cout<<"Case 4: Numbers with repetitions"<<std::endl;
    std::vector<int> tosearch = {1,1,1};
    std::vector<int> expected = {3};
    std::vector<int> result = sf.search(tosearch,u);
    printResult(expected,result);
}
void TestMaxMatchinAllRows(SearchFunction &sf, Searcher *u){
    
    std::cout<<"Case 4: Numbers in all rows"<<std::endl;
    std::vector<int> tosearch = {1};
    std::vector<int> expected = {1};
    std::vector<int> result = sf.search(tosearch,u);
    printResult(expected,result);
}
void testMaxMatch(SearchFunction &sf){
    
    Searcher *m = new MaxMatchSearcher();
    
    TestMaxMatchInRow1(sf,m);
    TestMaxMatchInRow5(sf,m);
    TestMaxMatchNotInMatrix(sf,m);
    TestExactRepetitionMaxMatchMatrix(sf,m);
    TestMaxMatchinAllRows(sf,m);
    
    delete m;
}

void printarr(std::vector<int> &arr){
    for(int i=0;i<arr.size();i++)
        std::cout<<arr[i]<<" ";
    std::cout<<std::endl;
}
void printResult(std::vector<int> &expected, std::vector<int> &result){
    std::cout<<"Expected: ";
    printarr(expected);
    std::cout<<"Result: ";
    printarr(result);
    if(expected == result)
        std::cout<<"Test OK"<<std::endl;
    else
        std::cout<<"Test Failed"<<std::endl;
}

