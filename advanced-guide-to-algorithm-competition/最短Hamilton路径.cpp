#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int dp[1 << 20][20], w[20][20], n;

int hamilton(int n) {
    memset(dp, 0x3f, sizeof(dp));
    dp[1][0] = 0;
    for (int i = 0; i < 1 << n; i++)
        for (int j = 0; j < n; j++)
            if (i >> j & 1)
                for (int k = 0; k < n; k++)
                    if (i >> k & 1)
                        dp[i][j] = min(dp[i][j], dp[i ^ 1 << j][k] + w[k][j]);
    return dp[(1 << n) - 1][n - 1];
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> w[i][j];

    cout << hamilton(n);

    return 0;
}
