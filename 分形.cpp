#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, lv = 1;
bool s[3000][3000];

void cpy(int x1, int y1, int x2, int y2, int nx, int ny){
    for(int i = 0; i <= x2 - x1; i++)
        for(int j = 0; j <= y2 - y1; j++)
            s[nx + i][ny + j] = s[x1 + i][y1 + j];
}

int main(){
    // freopen("out.txt", "w", stdout);
    s[1][1] = true;
    for(int i = 2; i <= 7; i++){
        cpy(1, 1, lv, lv, 1, lv * 2 + 1);
        cpy(1, 1, lv, lv, lv * 2 + 1, 1);
        cpy(1, 1, lv, lv, lv + 1, lv + 1);
        cpy(1, 1, lv, lv, lv * 2 + 1, lv * 2 + 1);
        lv *= 3;
    }

    int in;
    while(cin >> in && in != -1){
        lv = 1;
        while(--in) lv *= 3;
        for(int i = 1; i <= lv; i++){
            for(int j = 1; j <= lv; j++) printf("%c", s[i][j] ? 'X' : ' ');
            puts("");
        }
        puts("-");
    }

    return 0;
}
