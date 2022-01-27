#include <iostream>

using namespace std;

const int MOD = 1000000007;
int cache[101];

// Top-down 방식
int tiling(int width){
    if(width <= 1)
        return 1;
    int& ret = cache[width];
    if(ret != -1) 
        return ret;
    ret = (tiling(width - 1) + tiling(width - 2)) % MOD;
    return ret;
}

// Bottom-up 방식
int tiling2(int width){
    cache[0] = 0;
    cache[1] = 1;
    for(int i=2 ; i<=width ; i++)
        cache[i] = cache[i-1] + cache[i-2];
    return cache[width];
}