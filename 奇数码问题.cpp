#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, s[250010], ct, tmp[250010];

void merge(int l, int r){
    if(l == r) return;
    int mid = l + r >> 1;
    merge(l, mid);
    merge(mid + 1, r);
    int i = l, j = mid + 1;
    for(int k = l; k <= r; k++)
        if(j > r || i <= mid && s[i] <= s[j]) tmp[k] = s[i++];
        else tmp[k] = s[j++], ct += mid - i + 1;
    for(int i = l; i <= r; i++) s[i] = tmp[i];
}

int main(){
    int tmp;
    while(cin >> n){
        int ct1, ct2;
        int l = 1, r = n * n - 1;
        ct = 0;

        int t = r + 1, i = 1;
        while(t--){
            cin >> tmp;
            if(tmp) s[i++] = tmp;
        }
        
        merge(l, r);
        ct1 = ct;
        ct = 0;

        t = r + 1;
        i = 1;
        while(t--){
            cin >> tmp;
            if(tmp) s[i++] = tmp;
        }

        merge(l, r);
        ct2 = ct;
        if((ct1 & 1) == (ct2 & 1)) puts("TAK");
        else puts("NIE");
    }

    return 0;
}
