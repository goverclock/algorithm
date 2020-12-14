#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int ksm(int b, int p, int k){
    int ans = 1 % k;
    while(p){
        if(p & 1) ans = (long long)ans * b % k;
        b = (long long)b * b % k;
        p >>= 1;
    }
    return ans;
}

int b, p, k;

int main(){
    cin >> b >> p >> k;

    printf("%d^%d mod %d=%d", b, p, k, ksm(b, p, k));

    return 0;
}
