#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

typedef pair<long long, long long> PLL;
long long n, m, ans;
int k;
priority_queue<PLL, vector<PLL>, greater<PLL> > q;

int main() {
    scanf("%lld%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        long long a;
        scanf("%lld", &a);
        q.push(make_pair(a, 0LL));
    }

    while ((q.size() - 1) % (k - 1))
        q.push(make_pair(0LL, 0LL));
    while (q.size() >= k) {
        long long deep = -1, tmp = 0;
        for (int j = 1; j <= k; j++) {
            PLL dx = q.top();
            q.pop();
            tmp += dx.first;
            deep = max(deep, dx.second);
        }
        q.push(make_pair(tmp, deep + 1));
        ans += tmp;
    }
    printf("%lld\n%lld", ans, q.top().second);

    return 0;
}
