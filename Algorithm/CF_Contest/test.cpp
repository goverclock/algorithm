#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int from_cnt[11];
int from_to_cnt[11][11];
double possiblity[11][11];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string s;
    while (cin >> s) {
        int last = 0;
        for (auto j = s.begin(); j != s.end(); j++) {
            char i = *j;
            int num;
            if (i == 'x')
                num = 10;
            else
                num = i - '0';

            if (j + 1 != s.end()) from_cnt[num]++;
            if (last) from_to_cnt[last][num]++;
            last = num;
        }
    }

    for (int i = 1; i <= 10; i++)
        if (from_cnt[i])
            for (int j = 1; j <= 10; j++)
                possiblity[i][j] = (double)from_to_cnt[i][j] / from_cnt[i];

    puts("from_cnt");
    for (int i = 1; i <= 10; i++) printf("%d ", from_cnt[i]);
    puts("");

    puts("from_to_cnt");
    for (int i = 1; i <= 10; i++, puts(""))
        for (int j = 1; j <= 10; j++) printf("%d\t", from_to_cnt[i][j]);

    puts("possibility");
    for (int i = 1; i <= 10; i++, puts(""))
        for (int j = 1; j <= 10; j++) printf("%.4f\t", possiblity[i][j]);
    puts("");

    return 0;
}
