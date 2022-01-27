#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeSort(vector<int> arr){ //arr=38 27
    int arrsize = arr.size();
    if(arrsize == 1)         //기저사례 처리
        return arr;
    int half = arrsize/2;
    if(arrsize%2==1)
        half = arrsize/2 + 1;

    vector<int> leftarr;
    vector<int> rightarr;
    
    //반으로 분해하는 과정 -> 매개호출을 이용
	// 1,2,3,4,5라면 left -> 1,2,3 , right -> 4,5
    for(int i=0 ; i<half ; i++)
        leftarr.push_back(arr.at(i));
    for(int i=half ; i<arrsize ; i++)
        rightarr.push_back(arr.at(i));

    leftarr = mergeSort(leftarr); //27, 38
    rightarr = mergeSort(rightarr); //9, 43

    //병합과정 , 이미 배열들은 정렬된 상태이다
    //left -> 27, 38 , right -> 9, 43, 45
    //첫번째 index를 각각 저장해서 작은 숫자부터 새로운 배열에 저장
    vector<int> newarr;
    int leftindex = 0;
    int rightindex = 0;
    while(leftindex < leftarr.size() && rightindex < rightarr.size()){
        if(leftarr.at(leftindex) < rightarr.at(rightindex)){
            newarr.push_back(leftarr.at(leftindex));
            leftindex++;
        }
        else{
            newarr.push_back(rightarr.at(rightindex));
            rightindex++;
        }
    }
    //다 넣고 나면 right에서 43, 45만 남게 되는데 이것을 따로 또 넣어줘야 함
    //무조건 left, right 둘 중 하나는 다 들어갔으므로, 안들어간 부분만 넣어주면 됨

    while(leftindex < leftarr.size() || rightindex < rightarr.size()){
        //left가 다 들어갔을 경우
        if(leftindex == leftarr.size() ){
            newarr.push_back(rightarr.at(rightindex));
            rightindex++;
        }
        //right가 다 들어갔을 경우
        else{
            newarr.push_back(leftarr.at(leftindex));
            leftindex++;
        }
    }
    return newarr;
}

int main(){
    vector<int> v(1,38);
    v.push_back(27);
    v.push_back(43);
    v.push_back(9);
    v.push_back(3);
    v.push_back(82);
    v.push_back(10);
    // for(int i : v){
    //     cout<< i << " ";
    // }
    // cout<<endl;
    vector<int> wpqkf;
    wpqkf = mergeSort(v);
    for(int i : wpqkf){
        cout<< i << " ";
    }
}