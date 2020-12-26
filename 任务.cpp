#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, m, lct[110];
long long ans, ct;
struct S
{
    int x, y;
}a[100010], b[100010];          // a n机器, b m任务

bool cmp(S &a, S &b){
    if(a.x != b.x) return a.x > b.x;
    return a.y > b.y;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d%d", &a[i].x, &a[i].y);
    for(int i = 1; i <= m; i++) scanf("%d%d", &b[i].x, &b[i].y);
    sort(a + 1, a + 1 + n, cmp);
    sort(b + 1, b + 1 + m, cmp);

    int j = 1;
    for(int i = 1; i <= m; i++){
        while(j <= n && a[j].x >= b[i].x) {
            lct[a[j].y]++;
            j++;
        }
        for(int k = b[i].y; k <= 100; k++){
            if(lct[k]){
                ct++;
                lct[k]--;
                ans += 500 * b[i].x + 2 * b[i].y;
                break;
            }
        }
    }

    printf("%lld %lld\n", ct, ans); 

    return 0;
}
