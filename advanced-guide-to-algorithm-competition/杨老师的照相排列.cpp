#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

long long dp[31][31][31][31][31], k;
int N[6];

void solve() {
    memset(N, 0, sizeof(N));
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= k; ++i) scanf("%d", N + i);
    dp[0][0][0][0][0] = 1;

    for (int a = 0; a <= N[1]; a++)
        for (int b = 0; b <= min(a, N[2]); b++)
            for (int c = 0; c <= min(b, N[3]); c++)
                for (int d = 0; d <= min(c, N[4]); d++)
                    for (int e = 0; e <= min(d, N[5]); e++) {
                        long long &x = dp[a][b][c][d][e];
                        if (a && a - 1 >= b) x += dp[a - 1][b][c][d][e];
                        if (b && b - 1 >= c) x += dp[a][b - 1][c][d][e];
                        if (c && c - 1 >= d) x += dp[a][b][c - 1][d][e];
                        if (d && d - 1 >= e) x += dp[a][b][c][d - 1][e];
                        if (e) x += dp[a][b][c][d][e - 1];
                    }

    printf("%lld\n", dp[N[1]][N[2]][N[3]][N[4]][N[5]]);
}

int main() {
    while (cin >> k && k) solve();

    return 0;
}
