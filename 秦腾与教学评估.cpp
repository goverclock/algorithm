#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int T, n;
struct S{
    long long s, d, e;
}t[200010];

long long cnt(long long l, long long r){        // return Count
    long long ct = 0;
    long long begin, end;
    for(int i = 1; i <= n; i++){
        long long s = t[i].s, e = t[i].e, d = t[i].d;
        if(e < l || s > r) continue;
        if(l <= s) begin = s;
        else {
            long long k = (l - s - 1) / d + 1;
            if(s + k * d <= e)
                begin = s + k * d;
            else continue;
        }
        end = min(r, e);
        if(end - begin < 0) continue;
        ct += (end - begin) / d + 1;
    }
    return ct;
}

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%lld%lld%lld", &t[i].s, &t[i].e, &t[i].d);
        long long l = 0, r = (long long)(2147483648);
        bool bad = true;
        while(l < r && l >= 0){
            long long mid = l + r >> 1;
            if(cnt(l, mid) & 1) r = mid, bad = false;
            else l = mid + 1;
        }
        if(bad) puts("Poor QIN Teng:(");
        else printf("%lld %lld\n", l, cnt(l, l));
    }

    return 0;
}
