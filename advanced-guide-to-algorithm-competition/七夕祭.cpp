#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

int n, m, t, r[100010], c[100010];
long long ans;
int a[100010];

long long C() {
    long long ret = 0;
    for (int i = 1; i <= m; i++) a[i] = c[i] - t / m + a[i - 1];
    sort(a + 1, a + m + 1);
    for(int i = 1; i <= m; i++) ret += abs(a[i] - a[m + 1 >> 1]);
    return ret;
}

long long R() {
    long long ret = 0;
    for (int i = 1; i <= n; i++) a[i] = r[i] - t / n + a[i - 1];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) ret += abs(a[i] - a[n + 1 >> 1]);
    return ret;
}

int main() {
    cin >> n >> m >> t;
    int x, y;
    for (int i = 1; i <= t; i++) {
        cin >> x >> y;
        c[y]++;
        r[x]++;
    }
    if (!(t % m) && !(t % n)) {
        cout << "both ";
        ans = C() + R();
    } else if (!(t % n)) {
        cout << "row ";
        ans = R();
    } else if (!(t % m)) {
        cout << "column ";
        ans = C();
    } else {
        puts("impossible");
        return 0;
    }

    cout << ans << endl;

    return 0;
}
