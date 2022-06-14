#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, a[3010], b[3010], dp[3010][3010];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) scanf("%d", b + i);

    for (int i = 1; i <= n; i++) {
        int big = 1;
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];
            if (a[i] == b[j]) dp[i][j] = max(dp[i][j], big);
            if (a[i] > b[j]) big = max(big, dp[i - 1][j] + 1);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) res = max(res, dp[n][i]);
    printf("%d\n", res);

    return 0;
}
