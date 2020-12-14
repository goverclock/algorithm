#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

long long a, b, p;

long long mul64(long long a, long long b, long long p){
    long long ans = 0;
    while(b){
        if(b & 1) ans = (ans + a) % p;
        a = a * 2 % p;
        b >>= 1;
    }
    return ans;
}

int main(){
    cin >> a >> b >> p;

    cout << mul64(a, b, p) << endl;

    return 0;
}
