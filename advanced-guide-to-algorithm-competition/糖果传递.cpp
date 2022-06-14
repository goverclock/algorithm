#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

int n, s[1000010];
long long t, ans;

int main(){
    scanf("%d", &n);
    for(int i = 1;i <= n; i++){
        scanf("%d", s + i);
        t += s[i];
    }
    for(int i = 1; i <= n; i++) s[i] += s[i - 1] - t / n;
    sort(s + 1, s + 1 + n);
    int mid = s[(n + 1) >> 1];
    for(int i = 1; i <= n; i++) ans += abs(s[i] - mid);

    printf("%lld\n", ans);

    return 0;
}
