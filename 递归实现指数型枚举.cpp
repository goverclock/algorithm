// 本题我使用了两种做法

// 1.书中方法
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

vector<int> used;
int n;

void dfs(int x){
    if(x == n + 1){
        int l = used.size();
        for(int i = 0; i < l; i++) cout << used[i] << ' ';
        puts("");
    }else{
        dfs(x + 1);
        used.push_back(x);
        dfs(x + 1);
        used.pop_back();
    }
}

int main(){
    cin >> n;
    dfs(1);

    return 0;
}

// 2.我最熟悉的dfs
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n;
bool used[20];

void dfs(int x){
    if(x == n + 1){
        for(int i = 1; i <= n; i++)
            if(used[i]) cout << i << ' ';
        puts("");
    }else{
        dfs(x + 1);
        used[x] = true;
        dfs(x + 1);
        used[x] = false;
    }
}

int main(){
    cin >> n;
    dfs(1);

    return 0;
}
