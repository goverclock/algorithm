#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int c, l, ans;
struct SPF{
    int spf, ct;
}a[2510];
struct S{
    int minS, maxS;
}s[2510];

bool cmpS(S a, S b){
    return a.minS > b.minS;
}

bool cmpSPF(SPF a, SPF b){
    return a.spf > b.spf;
}

int main(){
    cin >> c >> l;
    for(int i = 1; i <= c; i++) cin >> s[i].minS >> s[i].maxS;
    for(int i = 1; i <= l; i++) cin >> a[i].spf >> a[i].ct;

    sort(s + 1, s + c + 1, cmpS);
    sort(a + 1, a + l + 1, cmpSPF);

    for(int i = 1; i <= c; i++)
        for(int j = 1; j <= l; j++)
            if(a[j].ct && a[j].spf >= s[i].minS && a[j].spf <= s[i].maxS){
                ans++;
                a[j].ct--;
                break;
            }
    cout << ans << endl;

    return 0;
}
