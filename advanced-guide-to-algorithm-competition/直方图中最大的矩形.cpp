#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

long long n, s[100000], w[100000];
long long ans;
void solve();

int main() {
    while (scanf("%d", &n)) {
        if(!n) break;
        solve();
    }

    return 0;
}

void solve() {
    int now, p = 0;
    memset(s, 0, sizeof(long long) * (n + 2));
    memset(w, 0, sizeof(long long) * (n + 2));
    for (int i = 1; i <= n + 1; i++) {
        if (i != n + 1)
            scanf("%d", &now);
        else
            now = 0;
        if (now > s[p])
            s[++p] = now, w[p] = 1;
        else {
            int wid = 0;
            while (s[p] > now) {
                wid += w[p];
                ans = max(ans, (long long)wid * s[p]);
                p--;
            }
            s[++p] = now, w[p] = wid + 1;
        }
    }
    printf("%lld\n", ans);
    ans = 0;
}
