#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
#define SIZE 30010

int fa[SIZE], d[SIZE], siz[SIZE], n;

inline int read() {
    char ch = getchar();
    int x = 0, f = 1;
    while (ch > '9' || ch < '0') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int get(int x) {
    if (x == fa[x]) return x;
    int root = get(fa[x]);
    d[x] += d[fa[x]];
    return fa[x] = root;
}
void merge(int x, int y) {
    x = get(x), y = get(y);
    fa[x] = y, d[x] = siz[y];
    siz[y] += siz[x];
}
void init() {
    for (int i = 1; i <= SIZE; i++) {
        fa[i] = i;
        // d[i] = 1;
        siz[i] = 1;
    }
}

int main() {
    int t = read(), x, y;
    char ch;
    init();

    while (t--) {
        cin >> ch;
        x = read(), y = read();
        if (ch == 'M')
            merge(x, y);
        else{
            int nx = get(x), ny = get(y);
            if(nx != ny) puts("-1");
            else printf("%d\n", abs(d[x] - d[y]) - 1);
        }
    }

    return 0;
}
