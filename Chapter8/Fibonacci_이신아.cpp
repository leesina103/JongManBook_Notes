#include <iostream>

using namespace std;

int cache[100];

// Top-down 방식
int fibonacci(int num){
    if(num == 1)
        return 1;
    if(num == 0)
        return 0;

    int& ret = cache[num];

    if(ret != -1)
        return ret;

    ret = fibonacci(num - 1) + fibonacci(num - 2);
    return ret;
}

// Bottom-up 방식
int fibonacci2(int num){
    cache[0] = 0;
    cache[1] = 1;
    for(int i=2 ; i<=num ; i++)
        cache[i] = cache[i-1] + cache[i-2];
    return cache[num];
}

int main(){
    // memset(cache, -1, sizeof(cache));
    fill_n(cache, sizeof(cache), -1);
    cout << fibonacci(7) << endl;
    cout << fibonacci2(7);
    return 0;
}

// 0 1 2 3 5 8 13
