#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int trie[1000010][26], tot = 1, ed[1000010];
char s[1000010];

void insert(char * str){
    int len = strlen(str), p = 1;
    for(int k = 0; k < len; k++){
        int ch = str[k] - 'a';
        if(!trie[p][ch]) trie[p][ch] = ++tot;
        p = trie[p][ch];
    }
    ed[p]++;
}

long long search(char *str){
    long long sum = 0;
    int len = strlen(str), p = 1;
    for(int k = 0; k < len; k++){
        p = trie[p][str[k] - 'a'];
        if(p) sum += ed[p];
    }
    return sum;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    while(n--){
        scanf("%s", s);
        insert(s);
    }
    while(m--){
        scanf("%s", s);
        printf("%lld\n", search(s));
    }

    return 0;
}
