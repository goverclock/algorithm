// 这是一道交互题, 我吃了不会玩vector的亏, 而且我也没有办法测试
// 所以依赖了题解, 企图改为我熟悉的二分写法但是失败了
// 为了不浪费时间只能暂时放弃这个问题

// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> specialSort(int N) {
        vector<int> s;
        s.push_back(1);
        for(int i = 2; i <= N; i++){
            int l = 0, r = s.size() - 1;
            while (l <= r)
            {
                int mid = l + r >> 1;
                if(compare(s[mid], i)) l = mid + 1;
                else r = mid - 1;
            }
            s.push_back(i);
            for(int j = s.size() - 2; j > r; j--) swap(s[j], s[j + 1]);
        }

        return s;
    }
};
