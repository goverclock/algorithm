#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> PII;
int n;
PII s[1010];

vector<int> mul(vector<int> a, int b) {
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i++) {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while (t) {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}

vector<int> div(vector<int> a, int b) {
    vector<int> c;
    bool isHead = true;
    for (int i = a.size() - 1, t = 0; i >= 0; i--) {
        t = t * 10 + a[i];
        int x = t / b;
        if (!isHead || x) {
            isHead = false;
            c.push_back(x);
        }
        t %= b;
    }
    reverse(c.begin(), c.end());
    return c;
}

vector<int> maxv(vector<int> a, vector<int> b) {
    if (a.size() > b.size()) return a;
    if (a.size() < b.size()) return b;
    if (vector<int>(a.rbegin(), a.rend()) > vector<int>(b.rbegin(), b.rend()))
        return a;
    return b;
}

int main() {
    scanf("%d", &n);
    int a, b;
    for (int i = 0; i <= n; i++) {
        scanf("%d%d", &a, &b);
        s[i] = {a * b, a};
    }
    sort(s + 1, s + n + 1);

    vector<int> cur(1, 1);
    vector<int> ans(1, 0);
    for (int i = 0; i <= n; i++) {
        if (i) ans = maxv(ans, div(cur, s[i].first / s[i].second));
        cur = mul(cur, s[i].second);
    }

    for (int i = ans.size() - 1; i >= 0; i--) printf("%d", ans[i]);
    puts("");

    return 0;
}
