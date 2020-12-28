#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef pair<int, int> PII;
int n, c, x[510], y[510], idx, idy;
PII s[510];

bool cmpX(PII a, PII b) { return a.first < b.first; }

bool check(int p) {
    for (int i = 1; i <= idx; i++) {
        PII tmp(x[i], -1);
        int begin = lower_bound(s + 1, s + n + 1, tmp, cmpX) - s;
        for (int j = 1; j <= idy; j++) {
            int sx = x[i], sy = y[j], ct = 0;
            for (int k = begin; s[k].first <= sx + p - 1 && k <= n; k++)
                if (s[k].second >= sy && s[k].second <= sy + p - 1) {
                    ct++;
                    if (ct >= c) return true;
                    if(ct + n - k < c) break;
                }
        }
    }
    return false;
}

int main() {
    // freopen("in.txt", "r", stdin);
    bool bx[10010], by[10010];
    memset(bx, 0, sizeof(bx));
    memset(by, 0, sizeof(by));
    scanf("%d%d", &c, &n);
    int a, b;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a, &b);
        s[i] = {a, b};
        bx[a] = true;
        by[b] = true;
    }
    s[0] = {-1, -1};
    for (int i = 1; i <= 10001; i++) {
        if (bx[i]) x[++idx] = i;
        if (by[i]) y[++idy] = i;
    }
    sort(s + 1, s + n + 1, cmpX);

    int l = 0, r = 10001;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    printf("%d\n", l);

    return 0;
}
