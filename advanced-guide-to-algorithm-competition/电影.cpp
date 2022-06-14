#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, m, a[200010], b[200010], c[200010], sct;
long long big = -1;
int ans;
int s[600010], ct[600010];

void discrete() {
    sort(s, s + 2 * m + n);
    sct = unique(s, s + 2 * m + n) - s;
}

int query(int x) { return lower_bound(s, s + sct, x) - s; }

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[sct++] = a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        s[sct++] = b[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> c[i];
        s[sct++] = c[i];
    }
    discrete();
    for(int i = 0; i < n; i++) ct[query(a[i])]++;
    for(int i = 0; i < m; i++){
        if((long long)(ct[query(b[i])] * 1000000 + ct[query(c[i])]) > big){
            ans = i;
            big = (long long)(ct[query(b[i])] * 1000000 + ct[query(c[i])]);
        }
        // big = max(big, );
    }
    cout << ans + 1 << endl;

    return 0;
}

// 只选取一个电影
