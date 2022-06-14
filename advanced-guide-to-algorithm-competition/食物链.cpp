// 拓展域做法

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, m, ans, fa[200000];

int get(int x) {
    if (x == fa[x]) return x;
    return fa[x] = get(fa[x]);
}
void merge(int x, int y) { fa[get(x)] = get(y); }

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= 3 * n; i++) fa[i] = i;

    while (m--) {
        int opr, x, y;
        scanf("%d%d%d", &opr, &x, &y);
        if (x > n || y > n) {
            ans++;
            continue;
        }

        if (opr == 1) {
            if (get(x) == get(y + n) || get(x) == get(y + n + n))
                ans++;
            else {
                merge(x, y);
                merge(x + n, y + n);
                merge(x + n + n, y + n + n);
            }
        } else {
            if (x == y || get(x) == get(y) || get(x) == get(y + n))
                ans++;
            else {
                merge(x, y + 2 * n);
                merge(x + n, y);
                merge(x + 2 * n, y + n);
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
