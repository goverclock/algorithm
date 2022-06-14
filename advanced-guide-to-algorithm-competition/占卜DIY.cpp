#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <deque>
using namespace std;

typedef pair<int, bool> P;
deque<P> q[14];
int life = 4, cur, from = 13, up[14], ans;

int main(){
    char tmp;
    for(int i = 1; i <= 13; i++)
        for(int j = 1; j <= 4; j++){
            tmp = getchar();
            getchar();
            if(tmp == '0') q[i].push_back(make_pair(10, false));
            else if (tmp == 'A') q[i].push_back(make_pair(1, false));
            else if(tmp == 'J') q[i].push_back(make_pair(11, false));
            else if(tmp == 'Q') q[i].push_back(make_pair(12, false));
            else if(tmp == 'K') q[i].push_back(make_pair(13, false));
            else q[i].push_back(make_pair(tmp - '0', false));
        }

    cur = q[13].front().first;
    q[13].pop_front();
    while(life){
        if(cur != 13){
            q[cur].push_front(make_pair(cur, true));
            from = cur;
            cur = q[from].back().first;
            q[from].pop_back();
        }else{
            life--;
            cur = q[13].front().first;
            q[13].pop_front();
        }
    }

    for(int i = 1; i <= 12; i++){
        while(!q[i].empty()){
            up[q[i].front().first] += q[i].front().second;
            q[i].pop_front();
        }
    }

    for(int i = 1; i <= 13; i++) ans += (up[i] == 4);
    printf("%d\n", ans);

    return 0;
}
