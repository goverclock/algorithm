#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

long long f[20], d[20];

int main(){
    d[1] = 1;
    for(int i = 1; i <= 12; i++) d[i + 1] = 2 * d[i] + 1;

    memset(f, 0x3f, sizeof(f));
    f[1] = 1;
    for(int i = 2; i <= 12; i++){
        for(int j = 1; j < i; j++)
            f[i] = min(f[i], 2 * f[j] + d[i - j]);
    }

    for(int i = 1; i <= 12; i++) cout << f[i] << endl;

    return 0;
}
