// 洛谷 平面最近点对(加强版)

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define INF 1e9 + 1

typedef pair<double, double> PDD;
int n;
PDD s[200010], tmp[200010];

double dist(PDD a, PDD b) {
    double dx = a.first - b.first, dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}
bool cmpY(PDD a, PDD b) { return a.second < b.second; }

double solve(int l, int r) {
    if (l == r) return INF;
    if (l + 1 == r) return dist(s[l], s[r]);
    double ans = INF;
    int mid = l + r >> 1;
    ans = min(solve(l, mid), solve(mid + 1, r));

    int idx = 0;
    for (int i = l; i <= r; i++)
        if (s[i].first >= s[mid].first - ans &&
            s[i].first <= s[mid].first + ans)
            tmp[++idx] = s[i];
    sort(tmp + 1, tmp + 1 + idx, cmpY);

    for (int i = 1; i <= idx - 1; i++)
        for (int j = 1; j + i <= idx; j++) {
            double d = dist(tmp[i], tmp[i + j]);
            if (d >= ans)
                break;
            else
                ans = d;
        }

    return ans;
}

int main() {
    // freopen("in2.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lf%lf", &s[i].first, &s[i].second);
    sort(s + 1, s + 1 + n);
    printf("%.4f\n", solve(1, n));

    return 0;
}

// 袭击, 这是抄的, 上面是自己写的
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
#define INF 1e8

const int N = 100100;
struct node {
    double x, y;
    int mk;
} a[N << 1], t[N << 1];
int n, m, i, j, k;

int cmp(node a, node b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int cmp2(node a, node b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

double dist(node a, node b) {
    if (a.mk == b.mk) return INF;
    double dx = (a.x - b.x), dy = (a.y - b.y);
    return sqrt(dx * dx + dy * dy);
}

double solve(int l, int r) {
    if (r - l == 0) return INF;
    if (r - l == 1) return dist(a[l], a[r]);
    int mid = l + r >> 1;
    double ans = min(solve(l, mid), solve(mid + 1, r));
    int ct = 0;
    for (int i = l; i <= r; i++)
        if (a[i].x >= a[mid].x - ans && a[i].x <= a[mid].x + ans)
            t[++ct] = a[i];
    sort(t + 1, t + 1 + ct, cmp2);
    for (int i = 1; i <= ct; i++)
        for (int j = i + 1; j <= ct; j++) {
            if (t[j].y >= t[i].y + ans) break;
            ans = min(ans, dist(t[i], t[j]));
        }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 1; i <= n; i++) {
            scanf("%lf%lf", &a[i].x, &a[i].y);
            a[i].mk = 0;
        }
        for (i = n + 1; i <= n << 1; i++) {
            scanf("%lf%lf", &a[i].x, &a[i].y);
            a[i].mk = 1;
        }
        n <<= 1;
        sort(a + 1, a + 1 + n, cmp);
        printf("%0.3lf\n", solve(1, n));
    }
}
