// 由于复杂度问题, 这个代码会TLE
// 改写成归并可以AC, 但是我想先放下, 这里花的时间已经很多了


#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#pragma GCC optimize(2)

long long k, n, m, t, ct;
int s[500010], tmp[500010];

bool check(int l, int r) {
    long long sum = 0;
    for (int i = l; i <= r; i++) tmp[i] = s[i];
    sort(tmp + l, tmp + r + 1);
    for (int i = 1; i <= m && r + 1 - l >= 2 * i; i++)
        sum += (tmp[l + i - 1] - tmp[r - i + 1]) *
               (tmp[l + i - 1] - tmp[r - i + 1]);
    return sum <= t;
}

int findR(int l) {  // 若从l到n的校验值满足, 则返回n
    int p = 1, r = l;
    if(check(l, n)) return n;
    while(p){
        if(check(l, r + p)){
            r += p;
            p *= 2;
        }else p /= 2;
    }
    return r;
}

int main() {
    scanf("%d", &k);
    while (k--) {
        ct = 0;
        scanf("%d%d%d", &n, &m, &t);
        for (int i = 1; i <= n; i++) scanf("%d", s + i);

        int l = 1, r;
        while (l != n + 1) {
            r = findR(l);
            l = r + 1;
            ct++;
        }
        printf("%d\n", ct);
    }

    return 0;
}
