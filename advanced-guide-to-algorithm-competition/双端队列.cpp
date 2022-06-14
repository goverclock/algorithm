#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef pair<int, int> PII;
int n, now, last, isup, l, r, ans;
PII s[200010];
int b[200010];

void solve();

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int tmp;
        scanf("%d", &tmp);
        s[i] = make_pair(tmp, i);
    }
    sort(s + 1, s + 1 + n);
    for (int i = 1; i <= n; i++) b[i] = s[i].second;

    last = 1e9;
    for (int i = 1; i <= n;) {
        now = s[i].first;
        l = i;
        while (s[i].first == now) i++;
        r = i - 1;

        solve();
    }


	printf("%d\n", ans);

    return 0;
}

void solve() {
    int big = -1, small = 1e9;
    for (int i = l; i <= r; i++) big = max(big, b[i]), small = min(small, b[i]);
    if (!isup)
        if (big < last)
            last = small;
        else
            last = big, isup = 1, ans++;
    else if (small > last)
        last = big;
    else
        last = small, isup = 0;

	if(!isup && r == n) ans++;
}
