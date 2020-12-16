#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MO = 9901;

int a, b, idx;
long long ans = 1;
struct S{
    int num, ct;
}fac[10000];

bool isPrime(int x){
    for(int i = 2; i * i <= x; i++)
        if(!(x % i)) return false;
    return true;
}

int ksm(int a, int b, int p) {
    int ans = 1 % p;
    while (b) {
        if (b & 1) ans = (long long)ans * a % p;
        a = (long long)a * a % p;
        b >>= 1;
    }
    return ans;
}

int sum(int p, int c) {
    if(!c) return 1;
    if (c & 1)
        return (1 + ksm(p, (c + 1) / 2, MO)) * sum(p, (c - 1) / 2) % MO;
    else
        return ((1 + ksm(p, c / 2, MO)) * sum(p, c / 2 - 1) + ksm(p, c, MO)) % MO;
}

void findFac(int x){
    // fac[0].num = 1;      // 1 不视为质数
    // fac[idx++].ct = 1;
    if(x == 0){             // 特判
        puts("0");
        exit(0);
    }
    int tmp = x;
    for(int i = 2; i <= tmp; i++)
        if(!(x % i) && isPrime(i)){
            fac[idx++].num = i;
            while(!(x % i)){
                fac[idx - 1].ct++;
                x /= i;
            }
        }
}

int main() {
    cin >> a >> b;
    findFac(a);

    for(int i = 0; i < 10000; i++)
        if(fac[i].num) ans = ans * sum(fac[i].num, fac[i].ct * b) % MO;

    cout << ans % MO;

    return 0;
}
