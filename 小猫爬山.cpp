#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int c[20], cab[20], n, w, ans;

void dfs(int now, int ct){
    if(ct >= ans) return;
    if(now == n + 1){
        ans = min(ans, ct);
        return;
    }
    for(int i = 1; i <= ct; i++){
        if(cab[i] + c[now] <= w){
            cab[i] += c[now];
            dfs(now + 1, ct);
            cab[i] -= c[now];
        }
    }
    cab[ct + 1] = c[now];
    dfs(now + 1, ct + 1);
    cab[ct + 1] = 0;
}

int main(){
    cin >> n >> w;
    for(int i = 1; i <= n; i++) cin >> c[i];
    ans = n;
    dfs(1, 0);
    cout << ans << endl;

    return 0;
}
