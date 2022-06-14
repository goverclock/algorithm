#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int n, ct, ans[50010];
struct S {
    int begin, end, num;
} t[50010];

struct node {
    int val, num;
};
struct cmp {
    bool operator()(const node &a, const node &b) { return a.val > b.val; }
};
priority_queue<node, vector<node>, cmp> q;

bool cmpS(S a, S b) { return a.begin < b.begin; }

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &t[i].begin, &t[i].end);
        t[i].num = i;
    }
    sort(t + 1, t + n + 1, cmpS);

    for (int i = 1; i <= n; i++) {
        bool bad = true;
        int to;
        if(!q.empty()) {
            to = q.top().num;
            if (t[i].begin > q.top().val) {
                ans[t[i].num] = to;
                q.pop();
                q.push({t[i].end, to});
                bad = false;
            }
        }

        if (bad) {
            ct++;
            q.push({t[i].end, ct});
            ans[t[i].num] = ct;
        }
    }

    printf("%d\n", ct);
    for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);

    return 0;
}
