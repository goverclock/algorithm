#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

long long s[500010], b[500010], n, ct;

void merge(int l, int r){
    if(r <= l) return;
    int mid = l + r >> 1;
    merge(l, mid);
    merge(mid + 1, r);
    int i = l, j = mid + 1;
    for(int k = l; k <= r; k++)
        if(j > r || i <= mid && s[i] < s[j]) b[k] = s[i++];
        else b[k] = s[j++], ct += mid - i + 1;
    for(int i = l; i <= r; i++) s[i] = b[i];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    while(cin >> n){
        if(!n) break;
        ct = 0;
        for(int i = 1; i <= n; i++) cin >> s[i];
        merge(1, n);
        cout << ct << endl;
    }

    return 0;
}
