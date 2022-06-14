#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define SIZE 1000000

int n, fa[SIZE + 10], dis[2 * SIZE + 10], idx;
struct S {
    int x, y, e;
} s[SIZE];

int get(int x) {
    if (x == fa[x]) return x;
    return fa[x] = get(fa[x]);
}
void merge(int x, int y) { fa[get(x)] = get(y); }
void init() {
    for (int i = 0; i <= n * 2 + 1; i++) fa[i] = i;
}
void discrete() {
    sort(dis + 1, dis + 1 + idx);
    idx = unique(dis + 1, dis + 1 + idx) - dis - 1;
}
int query(int x) { return lower_bound(dis + 1, dis + 1 + idx, x) - dis; }
bool cmp(S &a, S &b) { return a.e > b.e; }

void solve() {
    scanf("%d", &n);
    init();
    idx = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &s[i].x, &s[i].y, &s[i].e);
        dis[++idx] = s[i].x;
        dis[++idx] = s[i].y;
    }
    discrete();
    sort(s + 1, s + 1 + n, cmp);

    for (int i = 1; i <= n; i++){
        int nx = query(s[i].x), ny = query(s[i].y);
        if (s[i].e)
            merge(nx, ny);
        else if (get(nx) == get(ny)) {
            puts("NO");
            return;
        }
    }

    puts("YES");
}

int main() {
    // freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--) solve();

    return 0;
}
