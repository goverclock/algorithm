// 参考了题解


#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int t, n, m;

int main() {
    cin >> t;

    while (t--) {
        priority_queue<int> big;
        priority_queue<int, vector<int>, greater<int>> small;
        cin >> n >> m;
        cout << n << ' ' << (m + 1) / 2 << endl;
        int ct = 0;
        for (int i = 1; i <= m; i++) {
            cin >> n;
            small.push(n);
            if (big.size() && big.top() > small.top()) {
                int a = small.top(), b = big.top();
                small.pop(), big.pop();
                small.push(b), big.push(a);
            }
            if (small.size() > big.size() + 1) {
                big.push(small.top());
                small.pop();
            }
            if (i & 1) printf("%d%c", small.top(), ++ct % 10 ? ' ' : '\n');
        }
        if (ct % 10) cout << endl;
    }
    return 0;
}
