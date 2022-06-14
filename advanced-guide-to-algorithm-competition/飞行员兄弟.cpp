#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

bool s[5][5], tmp[5][5];
int ans = (1 << 16) - 1, ct;

bool check(int x){
    for(int i = 1; i <= 4 && x; i++)
        for(int j = 1; j <= 4 && x; j++){
            if(x & 1){
                for(int k = 1; k <= 4; k++) tmp[k][j] = !tmp[k][j];
                for(int k = 1; k <= 4; k++) tmp[i][k] = !tmp[i][k];
                tmp[i][j] = !tmp[i][j];
            }
            x >>= 1;
        }
    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 4; j++)
            if(!tmp[i][j]) return false;
    return true;
}

void cmp(int x){
    int ct1, ct2, t1 = ans, t2 = x;
    while(t1){
        if(t1 & 1) ct1++;
        t1 >>= 1;
    }
    while(t2){
        if(t2 & 1) ct2++;
        t2 >>= 1;
    }
    if(ct1 > ct2) ans = x;
}

int main(){
    char ch;
    for(int i = 1; i <= 4; i++, getchar())
        for(int j = 1; j <= 4; j++){
            scanf("%c", &ch);
            if(ch == '-') s[i][j] = true;
        }

    for(int i = 0; i <= (1 << 16) - 1; i++){
        memcpy(tmp, s, sizeof(s));
        if(check(i)) cmp(i);
    }

    int t = ans;
    while(t){
        if(t & 1) ct++;
        t >>= 1;
    }
    printf("%d\n", ct);
    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 4; j++){
            if(ans & 1) printf("%d %d\n", i, j);
            ans >>= 1;
        }

    return 0;
}
