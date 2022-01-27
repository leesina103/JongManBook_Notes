#include <iostream>
#include <cstring>

using namespace std;

int board[100][100];
int cache[100][100];

//메모이제이션 적용 안한 재귀 호출 알고리즘
//최악의 입력이 나왔을 때는, 수없이 많은 경로들을 일일이 탐색하지만 답을 못 찾는 경우가 있을 수 있다. 
int jump(int x, int y, int len){
    int ret = board[x][y];
    if(x >= len || y >= len)
        return false;
    if(x == len-1 && y == len-1)
        return true;
    return jump(x + ret, y, len) || jump(x, y+ ret, len);
}

int jump2(int x, int y , int len){
    int& ret = cache[x][y];
    if(x >= len || y >= len)
        return 0;
    if(x == len-1 && y == len-1)
        return 1;
    if(ret != -1)
        return ret;
    int jumpSize = board[x][y];
    ret = jump2(x + jumpSize, y, len) || jump2(x, y+ jumpSize, len);
    return ret;
}

// board와 cache배열을 따로 안쓰고 board배열에다가 직접 좌표를 바꿔서 메모이제이션 적용
int jump3(int x, int y , int len){
    int& ret = board[x][y];
    if(x >= len || y >= len)
        return 0;      

    if(x == len-1 && y == len-1)
        return 1;

    // if(ret == 1)
    //     return 1;

    if(ret == 0)
        return 0;
    
    ret = jump3(x + ret, y, len) || jump3(x, y+ ret, len);
    return ret;
}

int main(){
    memset(board, -1, sizeof(board));   //-1로 배열 초기화
    memset(cache, -1, sizeof(cache));   //-1로 배열 초기화
    int a;
    for(int i=0 ; i<7 ; i++)
        for(int j=0 ; j<7 ; j++){
            cin >> a;
            board[i][j] = a;
        }

    // if(jump(0,0,7))
    //     cout<<"YES";
    // else
    //     cout<<"NO";

    // int n = jump2(0,0,7);
    int n = jump3(0,0,7);
    if(n == 1)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}

// 2 5 1 6 1 4 1
// 6 1 1 2 2 9 3
// 7 2 3 2 1 3 1
// 1 1 3 1 7 1 2
// 4 1 2 3 4 1 2
// 3 3 1 2 3 4 1
// 1 5 2 9 4 7 0
// YES
// 2 5 1 6 1 4 1
// 6 1 1 2 2 9 3
// 7 2 3 2 1 3 1
// 1 1 3 1 7 1 2
// 4 1 2 3 4 1 3
// 3 3 1 2 3 4 1
// 1 5 2 9 4 7 0 
// NO