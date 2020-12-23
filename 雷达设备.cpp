#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, d, ans;
double pos = -1e8;
struct S {
    double l, r;
} s[1010];

bool cmp(S &a, S &b) { return a.l < b.l; }

int main() {
    double x, y;
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; i++) {
        scanf("%lf%lf", &x, &y);
        if (y > d) {
            puts("-1");
            return 0;
        }
        s[i].l = x - sqrt((double)(d * d - y * y));
        s[i].r = x + sqrt((double)(d * d - y * y));
    }

    sort(s + 1, s + n + 1, cmp);

    for (int i = 1; i <= n; i++) {
        if (pos < s[i].l) {
            ans++;
            pos = s[i].r;
        } else
            pos = min(pos, s[i].r);
    }

    printf("%d\n", ans);

    return 0;
}
