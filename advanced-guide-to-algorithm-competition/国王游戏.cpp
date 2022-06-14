// 我过了这题的感觉就像是捡到了一吨金块

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef pair<int, int> PII;
int n, cur[5000], curtmp[5000], ans[5000], tmp[5000], lena = 0, lenc = 1, lent = 1;
PII s[1010];

int mul1(int x, int l) {
    memset(tmp, 0, sizeof(tmp));

    for (int i = 1; i <= l; i++) tmp[i] = cur[i] * x;
    
    for (int i = 1; i < 4999; i++) {
        tmp[i + 1] += tmp[i] / 10;
        tmp[i] %= 10;
    }
    l = 4999;
    while(!tmp[l] && l) l--;
    l = (l ? l : 1);
    for (int i = 1; i <= 4999; i++) cur[i] = tmp[i];
    return l;
}

int div1(int x, int l) {
    memset(tmp, 0, sizeof(tmp));
    memcpy(curtmp, cur, sizeof(cur));

    for (int i = l; i >= 1; i--) {
        tmp[i] = curtmp[i] / x;
        curtmp[i - 1] += (curtmp[i] % x) * 10;
    }
    while (!tmp[l] && l) l--;
    l = (l ? l : 1);
    for (int i = l; i >= 1; i--) curtmp[i] = tmp[i];

    return l;
}

void cmp() {
    bool big = false;

    if (lent != lena)
        big = lent > lena;
    else
        for (int i = lent; i >= 1; i--)
            if (ans[i] != curtmp[i]) {
                big = curtmp[i] > ans[i];
                break;
            }
    if (big) {
        for (int i = lent; i >= 1; i--) ans[i] = curtmp[i];
        lena = lent;
    }
}

int main() {
    int a, b;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        scanf("%d%d", &a, &b);
        s[i] = {a * b, b};
    }

    cur[1] = 1;
    curtmp[1] = 1;
    lenc = mul1(s[0].first / s[0].second, lenc);
    sort(s + 1, s + 1 + n);

    for (int i = 1; i <= n; i++) {
        lent = div1(s[i].second, lenc);  // curtmp = cur, curtmp /= b
        cmp();                           // cur_tmp > ans ?
        lenc = mul1(s[i].first / s[i].second, lenc);  // cur *= a / b
    }

    int head = 4999;
    while (!ans[head] && head) head--;
    head = (head ? head : 1);
    for (int i = head; i >= 1; i--) printf("%d", ans[i]);
    putchar('\n');

    return 0;
}

// 下面是题解区做法

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
