#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int n, t, num[10000010], tmp, cs;
char opr[10];
void solve();

int main() {
    while (scanf("%d", &t)) {
        if (!t) break;
        cs++;
        solve();
    }

    return 0;
}

void solve() {
    queue<int> q[1010], q0;
    for (int i = 1; i <= t; i++) {
        int ct;
        // q0.push(i);
        scanf("%d", &ct);
        for (int j = 1; j <= ct; j++) {
            scanf("%d", &tmp);
            num[tmp] = i;
        }
    }
    printf("Scenario #%d\n", cs);
    while (scanf("%s", opr)) {
        if (opr[0] == 'E') {
            scanf("%d", &tmp);
            if (q[num[tmp]].empty()) q0.push(num[tmp]);
            q[num[tmp]].push(tmp);
        } else if (opr[0] == 'D') {
            int head = q0.front();
            if (q[head].empty()) q0.pop();
            head = q0.front();
            printf("%d\n", q[head].front());
            q[head].pop();
        } else
            break;
    }
    putchar('\n');
}
