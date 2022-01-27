#include <iostream>
#include <vector>

using namespace std;

//방식은 MergeSort와 매우 비슷
vector<int> quickSort(vector<int> arr){
    int arrsize = arr.size();

    if(arr.empty())       //비어있을 때
        return arr;
    if(arrsize==1)       //기저사례 처리
        return arr;

    //기준 수를 맨 뒤의 수로 지정
    int last = arr.at(arrsize-1); //9
    arr.pop_back();

    vector<int> left;
    vector<int> right;

    for(int e : arr){
        if(e < last)
            left.push_back(e);
        else
            right.push_back(e);
    }

    left = quickSort(left); //3
    right = quickSort(right); //10

    left.push_back(last);
    for(int e : right)
        left.push_back(e);
    return left;
}

int main(){
    vector<int> test;
    test.push_back(38);
    test.push_back(27);
    test.push_back(43);
    test.push_back(9);
    test.push_back(3);
    test.push_back(82);
    test.push_back(10);
    // for(int i : test)
    //     cout<<i<<" ";
    // if(test.empty())
    //     cout<<1;
    // for(int i : test)
    //     cout<<2;

    vector<int> qqq;
    qqq = quickSort(test);
    for(int i : qqq)
        cout<<i<<" ";
}