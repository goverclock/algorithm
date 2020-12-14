#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int INF = 0x7fffffff;

char s[5][5], save[5][5];
int n, ans;

int ct1(int x) {
    int sum = 0;
    while (x) {
        sum += x & 1;
        x >>= 1;
    }
    return sum;
}

void click(int x, int y) {
    int dx[5] = {1, -1, 0, 0, 0}, dy[5] = {0, 0, 1, -1, 0};
    for (int i = 0; i < 5; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
            s[nx][ny] = (s[nx][ny] == '0' ? '1' : '0');
    }
}

void dfs(int x, int n) {
    if(n > 6) return;
    if(x == 5){
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                if(s[i][j] == '0') return;
        ans = min(ans, n);
    }else{
        int adi = 0;
        for(int i = 0; i < 5; i++)
            if(s[x - 1][i] == '0'){
                click(x, i);
                adi++;
            }
        dfs(x + 1, n + adi);
    }
}

int main() {
    cin >> n;

    while (n--) {
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++) cin >> save[i][j];
        ans = INF;

        for (int i = 0; i < 32; i++) {      // first row
            memcpy(s, save, sizeof(s));
            int base = ct1(i);
            for (int j = 0; j < 5; j++)
                if (i >> j & 1) click(0, j);
            dfs(1, base);
        }

        if (ans == INF)
            cout << "-1" << endl;
        else
            cout << ans << endl;
    }

    return 0;
}
