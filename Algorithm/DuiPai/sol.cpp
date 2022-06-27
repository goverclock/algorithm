// freopen("data.in", "r", stdin);
// freopen("data.out", "w", stdout);

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, m, a[1010], b[1010];

void solve() {
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + m);

    int p1 = 1, p2 = 1, ans = 0;
    for (;p2 <= m && p1 <= n; p2++) {
        while(p1 < n && a[p1] == a[p1 + 1]) p1++;
        while(p2 < m && b[p2] == b[p2 + 1]) p2++;

        while (a[p1] < b[p2] + ans && p1 < n) p1++;
        while (a[p1] > b[p2] + ans && p2 < m) p2++;
        while (a[p1] == b[p2] + ans && p1 <= n) ans++, p1++;
    }
    printf("%d\n", ans);
}

int main() {
    freopen("data.in", "r", stdin);
freopen("data.out", "w", stdout);
    while (cin >> n >> m) solve();

    return 0;
}
