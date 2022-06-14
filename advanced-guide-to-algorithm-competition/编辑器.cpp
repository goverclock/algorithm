    #include <algorithm>
    #include <cstdio>
    #include <cstring>
    #include <iostream>
    #include <stack>
    using namespace std;

    int p, q, k, sum[1000010], f[1000010];
    stack<int> a, b;
    char ch;

    void I() {
        scanf("%d", &k);
        a.push(k);
        p = a.size();
        sum[p] = sum[p - 1] + a.top();
        f[p] = max(f[p - 1], sum[p]);
    }
    void D() {
        if (!a.empty()) a.pop();
    }
    void L() {
        if(a.empty()) return;
        b.push(a.top());
        a.pop();
    }
    void R() {
        if(b.empty()) return;
        a.push(b.top());
        b.pop();
        p = a.size();
        sum[p] = sum[p - 1] + a.top();
        f[p] = max(f[p - 1], sum[p]);
    }
    void Q() {
        scanf("%d", &k);
        printf("%d\n", f[k]);
    }

    int main() {
        scanf("%d", &q);
        fill(f, f + 1000000, -1000000000);
        while (q--) {
            cin >> ch;
            if (ch == 'I')
                I();
            else if (ch == 'D')
                D();
            else if (ch == 'L')
                L();
            else if (ch == 'R')
                R();
            else if (ch == 'Q')
                Q();
        }

        return 0;
    }
