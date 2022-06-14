// 这题难度是困难,看了题解后改改加了点注释帮助理解
// 毕竟我不能纠缠

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

long long n, a, b;
int T;
typedef pair<long long, long long> PLL;

PLL dfs(long long n, long long m) {                 // n级城市中编号m房屋的坐标
    if (n == 0) return make_pair(0, 0);
    long long len = 1 << (n - 1), ct = len * len;   // 小一级的城市的长度, 总房屋数

    PLL pos = dfs(n - 1, m % ct);                   // m % ct 即当前城市m在小一级城市中的编号
    long long x = pos.first, y = pos.second;        // 小一级城市中的坐标

    long long ang = m / ct;                         // 该表达式计算旋转方向

    if (ang == 0) return make_pair(y, x);
    if (ang == 1) return make_pair(x, y + len);
    if (ang == 2) return make_pair(x + len, y + len);
    return make_pair(2 * len - 1 - y, len - 1 - x);
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> a >> b;
        PLL p1 = dfs(n, a - 1);
        PLL p2 = dfs(n, b - 1);
        long long dx = p1.first - p2.first, dy = p1.second - p2.second;
        double ans = (sqrt(double(dx * dx + dy * dy)) * 10);
        printf("%.0f\n", ans);
    }
    return 0;
}
