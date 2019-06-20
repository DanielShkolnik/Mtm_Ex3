#include <iostream>
#include <vector>
#include <assert.h>
#include <string.h>
using std::string;
/*
template <class container,class Compare>
int countPairs(container first, const container last, Compare compare) {
   //add here your first function
}
 */
//**********************************

template <class Iterator,class Predicate>
int countPairs(Iterator first, Iterator last, Predicate predicate){
    int count = 0;
    for(Iterator i = first; i != last;++i){
        Iterator j = i;
        ++j;
        while (j != last){
            if(predicate(*i,*j) || predicate(*j,*i)){
                count++;
            }
            j++;
        }
    }
    return count;
}

//**********************************
bool compare(int x1,int x2){
    return x1<x2;
}

bool predict(int i, int j){
    return (i<0 || j<0);
}

bool isSorted(std::vector<int> v){
    std::vector<int> difference;
    for(auto i = v.begin(); i!=v.end()-1;i++){
        difference.push_back(*(i+1)-*i);
    }
    difference.push_back(0);
    int pairsCount = countPairs(difference.begin(),difference.end(),predict);
    return pairsCount == 0;
}

bool compareint2(int x1,int x2){
    return x2<x1;
}
bool comparestrings(string& s1, string &s2){
    return s1<s2;
}
bool comparestringsopposite(string& s1,string & s2){
    return s1>s2;
}
class A{
public:
    int x;
    A(int x){
        x=x;
    }
    bool operator<(A& a){
        return x<a.x;
    }
};
bool compareA(A& a1,A& a2){
    return a1<a2;
}
void TEST1(){
    std::cout<<"TEST1...";
    std::vector<int> check;
    check.push_back(1);
    check.push_back(2);
    check.push_back(3);
    check.push_back(4);
    check.push_back(5);
    check.push_back(6);
    check.push_back(10);
    check.push_back(22);
    check.push_back(30);
    check.push_back(40);
    check.push_back(53);
    check.push_back(64);
    int success=1;
    int test1 = countPairs(check.begin(), check.end(), compare);
    if(test1!=66) success=0;
    if (isSorted(check)!=1) success=0;
    std::cout<<(success?"SUCCESS":"FAILED")<<std::endl;
}
void TEST2(){
    std::cout<<"TEST2...";
    std::vector<int> check;
    check.push_back(1);
    check.push_back(2);
    check.push_back(32);
    check.push_back(4);
    check.push_back(5);
    check.push_back(6);
    check.push_back(22);
    check.push_back(22);
    check.push_back(22);
    check.push_back(22);
    check.push_back(22);
    check.push_back(64);
    int success=1;
    if(countPairs(check.begin(), check.end(), compare)!=56) success=0;
    if(isSorted(check)!=0)success=0;
    std::cout<<(success?"SUCCESS":"FAILED")<<std::endl;

}
void TEST3(){
    std::cout<<"TEST3...";
    std::vector<int> check;
    check.push_back(1);
    check.push_back(2);
    check.push_back(3);
    check.push_back(4);
    check.push_back(5);
    check.push_back(6);
    check.push_back(1);
    int success=1;
    if(countPairs(check.begin(), check.end(), compare)!=20) success=0;
    if(isSorted(check)!=0)success=0;
    std::cout<<(success?"SUCCESS":"FAILED")<<std::endl;
}
void Test4(){
    std::cout<<"TEST4...";
    std::vector<int> check;
    check.push_back(1);
    check.push_back(2);
    int success=1;
    if(countPairs(check.begin(), check.end(), compareint2)!=1) success=0;
    if(isSorted(check)!=1)success=0;
    std::cout<<(success?"SUCCESS":"FAILED")<<std::endl;
}
void TEST5(){
    std::cout<<"TEST5...";
    std::vector<int> check;
    check.push_back(10);
    check.push_back(2);
    int success=1;
    if(countPairs(check.begin(), check.end(), compare)!=1) success=0;
    if(isSorted(check)!=0)success=0;
    std::cout<<(success?"SUCCESS":"FAILED")<<std::endl;
}
void TEST6(){
    std::cout<<"TEST6...";
    std::vector<string> check;
    check.emplace_back("a");
    check.emplace_back("aa");
    check.push_back("b");
    check.push_back("bb");
    check.push_back("cc");
    check.push_back("dd");
    check.push_back("ddc");
    int success=1;
    if(countPairs(check.begin(), check.end(), comparestrings)!=21) success=0;
    std::cout<<(success?"SUCCESS":"FAILED")<<std::endl;
}
void TEST7(){
    std::cout<<"TEST7...";
    std::vector<string> check;
    check.push_back("d");
    check.push_back("d");
    check.push_back("c");
    int success=1;
    if(countPairs(check.begin(), check.end(), comparestringsopposite)!=2) success=0;
    std::cout<<(success?"SUCCESS":"FAILED")<<std::endl;
}
int main() {
    TEST1();
    TEST2();
    TEST3();
    Test4();
    TEST5();
    TEST6();
    TEST7();
    return 0;
}
