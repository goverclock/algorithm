#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

long long n, pos, neg;
long long a[100010];

int main() {
    scanf("%d", &n);
    int tmp;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        tmp = a[i] - a[i - 1];
        if (i != 1) tmp > 0 ? pos += tmp : neg += -tmp;
    }

	printf("%lld\n%lld\n", max(pos, neg), abs(pos - neg) + 1);

    return 0;
}
