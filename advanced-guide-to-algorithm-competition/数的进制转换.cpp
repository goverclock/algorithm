#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

char A[1010];
int A_int[1010], ans[1010], idx;
int t, from, to;

int div1(int x, int l) {
    int tmp[1010];
    A_int[0] = 0;

    for (int i = l; i >= 1; i--) {
        tmp[i] = A_int[i] / x;
        A_int[i - 1] += (A_int[i] % x) * from;
    }
    while (!tmp[l] && l) l--;
    for (int i = l; i >= 1; i--) A_int[i] = tmp[i];

    return l;
}

int main() {
    // freopen("out.txt", "w", stdout);
    scanf("%d", &t);

    while (t--) {
        scanf("%d%d%s", &from, &to, A);

        idx = 0;
        int len = strlen(A);
        for (int i = len - 1; i >= 0; i--) {  // turn A to A_int
            if (A[i] >= '0' && A[i] <= '9')
                A_int[len - i] = A[i] - '0';
            else if (A[i] >= 'A' && A[i] <= 'Z')
                A_int[len - i] = A[i] - 'A' + 10;
            else if (A[i] >= 'a' && A[i] <= 'z')
                A_int[len - i] = A[i] - 'a' + 36;
        }

        while (len = div1(to, len)) ans[++idx] = A_int[0] / from;
        ans[++idx] = A_int[0] / from;

        printf("%d %s\n%d ", from, A, to);
        for (int i = idx; i >= 1; i--) {
            if (ans[i] >= 0 && ans[i] < 10)
                printf("%d", ans[i]);
            else if (ans[i] >= 10 && ans[i] <= 35)
                printf("%c", ans[i] + 'A' - 10);
            else if (ans[i] >= 36 && ans[i] <= 61)
                printf("%c", ans[i] + 'a' - 36);
        }
        puts("\n");
    }

    return 0;
}
