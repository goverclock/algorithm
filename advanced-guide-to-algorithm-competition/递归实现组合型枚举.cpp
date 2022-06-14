#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

vector<int> used;
int n, m;

void dfs(int x){
    if(used.size() > m || used.size() + (n - x + 1) < m) return;
    if(x == n + 1){
        int l = used.size();
        for(int i = 0; i < l; i++) cout << used[i] << ' ';
        puts("");
    }else{
        used.push_back(x);    // 注意这里的顺序, 题目要求字典序输出
        dfs(x + 1);
        used.pop_back();
        dfs(x + 1);
    }
}

int main(){
    cin >> n >> m;
    dfs(1);

    return 0;
}
