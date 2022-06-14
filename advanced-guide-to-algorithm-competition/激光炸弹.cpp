#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int s[5010][5010], n, r, x, y, w, ans;

int sum(int x, int y) {
    int nx = (x - r >= 0 ? x - r : 0), ny = (y - r >= 0 ? y - r : 0);
    return s[x][y] + s[nx][ny] - s[nx][y] - s[x][ny];
}

int main() {
    cin >> n >> r;
    while (n--) {
        cin >> x >> y >> w;
        s[x + 1][y + 1] += w;
    }

    for(int i = 1; i < 5010; i++)
        for(int j = 1; j < 5010; j++)
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];

    for(int i = 0; i < 5010; i++)
        for(int j = 0; j < 5010; j++)
            ans = max(ans, sum(i,j));
    cout << ans;

    return 0;
}
