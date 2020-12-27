#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

int n, x[10010], y[10010];
long long ans;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d%d", x + i, y + i);
    sort(x + 1, x + n + 1);
    for(int i = 1; i <= n; i++) x[i] -= i;
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);

    for(int i = 1; i <= n; i++) ans += abs(y[i] - y[(n + 1) / 2]);
    for(int i = 1; i <= n; i++) ans += abs(x[i] - x[(n + 1) / 2]);

    printf("%lld", ans);

    return 0;
}
