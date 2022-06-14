#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int N = 3e4 + 10;

int nxt[N], head[N], ver[N], deg[N], tot, cnt, a[N], n, m;
bitset<N> f[N];
void add(int x, int y) {
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
    deg[y]++;
}
void topsort(void) {
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0) q.push(i);
    while (q.size()) {
        int x = q.front();
        a[++cnt] = x;
        q.pop();
        for (int i = head[x]; i; i = nxt[i]) {
            int y = ver[i];
            deg[y]--;
            if (!deg[y]) q.push(y);
        }
    }
}
void calc() {
    for (int j = cnt; j; j--) {
        int x = a[j];
        f[x][x] = 1;
        for (int i = head[x]; i; i = nxt[i]) {
            int y = ver[i];
            f[x] |= f[y];
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y);
    }
    topsort();
    calc();
    for (int i = 1; i <= n; i++) cout << f[i].count() << endl;
    return 0;
}
