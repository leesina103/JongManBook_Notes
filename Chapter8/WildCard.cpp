#include <iostream>
#include <string>

using namespace std;

// (ex) he?p -> help(o), hellp(x)
bool findWildCard(string pattern, string filename){
    int pindex = 0;                                   // index를 따로 설정해주기
    int findex = 0;
    for(int pindex = 0 ; pindex < pattern.length() ; pindex++){     //while문으로 변경?
        char s = pattern.at(pindex);
        if(s == '?'){                                    // '?'면, 한칸 건너뛰기
            pindex++;
            findex++;
        }
        else if(s == '*'){

        }
        else if(pattern.at(pindex) != filename.at(pindex))      // 문자가 다를 경우
            break;
        findex++;
    }
    cout<< "pindex : " << pindex << endl;
    if(pindex == pattern.length())      //끝까지 못가고 break됬으면 다른 문자열이므로 false
        return true;
    else
        return false;
}

int main(){
    string pattern = "he?p";
    string filename = "help";
    if(findWildCard(pattern, filename))
        cout << "true";
    else
        cout << "false";

    // string str  = "abc";
    // char c = 'a';
    // if(c =='a')
    //     cout << "tttt";
    // else
    //     cout << 1;
    // cout << str.at(0) <<endl;
    // cout << str.compare("abc"); //같으면 0반환
}