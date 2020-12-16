#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

int n, m, p, h, s[10010], d[10010];
map<pair<int, int>, bool> exi;

int main(){
    cin >> n >> p >> h >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        if(exi[make_pair(a, b)]) continue;
        d[a + 1]--;
        d[b]++;
        exi[make_pair(a, b)] = true;
    }

    for(int i = 0; i < n; i++){
        s[i + 1] = s[i] + d[i + 1];
        cout << s[i + 1] + h << endl;
    }

    return 0;
}
