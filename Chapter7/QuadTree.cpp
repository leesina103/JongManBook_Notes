#include <iostream>
#include <string>

using namespace std;

string quadTree(string str){
    string first = str.substr(0,1);

    if(first.compare("w"))
        return "w";
    if(first.compare("b"))
        return "b";

    string upperLeft = quadTree(str.substr(1));
    string upperRight = quadTree(str.substr(2));
    string lowerLeft = quadTree(str.substr(3));
    string lowerRight = quadTree(str.substr(4));
    first += lowerLeft + lowerRight + upperLeft + upperRight;
    return first;
}

int main(){
    string str = "xwwwb";
    string test = quadTree(str);
    cout<<str<<endl;
    cout<< test;

    
    // if(str.substr(0,0).compare("a")){
    //     cout<<123;
    // }
}