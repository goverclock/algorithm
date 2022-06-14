#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > p;
pair<int, int> a[10010];
int n, m, i, j;
inline void read(int& x) {
    x = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
}

int main() {
    while (scanf("%d", &n) != EOF) {
        if (!n) {
            puts("0");
            continue;
        }
        for (int i = 1; i <= n; i++) {
            read(a[i].second);
            read(a[i].first);
        }
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++) {
            if (a[i].first > p.size())
                p.push(a[i].second);
            else if (a[i].first == p.size() && a[i].second > p.top()) {
                p.pop();
                p.push(a[i].second);
            }
        }
        long long ans = 0;
        while (!p.empty()) {
            ans += p.top();
            p.pop();
        }
        printf("%lld\n", ans);
    }
    return 0;
}
