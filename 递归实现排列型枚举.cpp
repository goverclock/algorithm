// 我和书上的做法一致, 经典问题

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, pos[10];
bool used[10];

void dfs(int x){
    if(x == n + 1){
        for(int i = 1; i <= n; i++)
            cout << pos[i] << ' ';
        puts("");
    }else{
        for(int i = 1; i <= n; i++)
            if(!used[i]){
                pos[x] = i;
                used[i] = true;
                dfs(x + 1);
                used[i] = false;
            }
    }
}

int main(){
    cin >> n;

    dfs(1);

    return 0;
}
