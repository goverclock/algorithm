#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const double eps = 1e-5;

int n, f;
double s[1000010], sum[1000010];

bool C(double x){
    double ans = -1;
    double small = 100000000.0;
    for(int i = 0; i < n; i++) sum[i + 1] = sum[i] + s[i + 1] - x;

    for(int i = f; i <= n; i++){           // 理解这里需要花费一些功夫
        small = min(small, sum[i - f]);    // 思维还是欠练的
        ans = max(ans, sum[i] - small);
    }    

    return ans >= 0;
}

int main(){
    cin >> n >> f;
    for(int i = 1; i <= n; i++) cin >> s[i];

    double l = -1, r = 100000000;
    while(r > eps + l){
        double mid = (l + r) / 2.0;
        if(C(mid)) l = mid;
        else r = mid;
    }
    cout << int(r * 1000) << endl;      // 注意这个输出方式, 向下取整, 试了其它的许多方法没有发现其它正确的做法

    return 0;
}
