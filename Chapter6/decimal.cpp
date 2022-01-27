#include <iostream>
using namespace std;

//분수a/b의 소수 표현을 출력한다
//a>=0, b>0이라고 가정함
void printDecimal(int a, int b) {
    int iter = 0;
    int count = 0;
    while (a > 0) {
        //첫 번째와 두 번째 사이에 소수점을 찍는다
        if (iter++ == 1) 
            cout << '.';
        cout << a / b;
        a = (a % b) * 10;
        count++;
        if(count==b+1){
            
        }
    }
}

int main() {
    printDecimal(3,8);
}
