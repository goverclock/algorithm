#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define fic(i, a, b) for (int i = a; i >= b; i--)
#define MOD 131
const int N = 1000007;
char s[N];
unsigned long long f1[N], f2[N], p[N];
int ans, t, l, r, mid;
unsigned long long Hash1(int i, int j) {
    return (f1[j] - f1[i - 1] * p[j - i + 1]);
}
unsigned long long Hash2(int i, int j) {
    return (f2[i] - f2[j + 1] * p[j - i + 1]);
}
void init() {
    p[0] = 1;
    fir(i, 1, N - 1) p[i] = p[i - 1] * 131;
}
int main() {
    init();
    while (++t) {
        ans = 0;
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        if (strcmp(s + 1, "END") == 0) return 0;
        f2[len + 1] = 0;
        fir(i, 1, len) f1[i] = f1[i - 1] * MOD + (s[i] - 'a' + 1);
        fic(i, len, 1) f2[i] = f2[i + 1] * MOD + (s[i] - 'a' + 1);
        fir(i, 1, len) {
            l = 0, r = min(i - 1, len - i);
            while (l < r) {
                mid = l + r + 1 >> 1;
                if (Hash1(i - mid, i - 1) == Hash2(i + 1, i + mid))
                    l = mid;
                else
                    r = mid - 1;
            }
            ans = max(l << 1 | 1, ans);
            l = 0, r = min(i - 1, len - i + 1);
            while (l < r) {
                mid = l + r + 1 >> 1;
                if (Hash1(i - mid, i - 1) == Hash2(i, i + mid - 1))
                    l = mid;
                else
                    r = mid - 1;
            }
            ans = max(l << 1, ans);
        }
        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}
