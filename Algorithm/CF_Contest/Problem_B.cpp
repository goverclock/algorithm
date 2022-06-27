#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        auto ans = new vector<vector<int>>;
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (i <= 2 || nums[i] != nums[i - 3]) tmp.push_back(nums[i]);
        n = tmp.size();

        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++) {
                int cur = tmp[i] + tmp[j];
                int pos = lower_bound(tmp.begin() + j + 1, tmp.end(), -cur) -
                          tmp.begin();
                if (pos != n && tmp[pos] + cur == 0) {
                    vector<int> nv = {tmp[i], tmp[j], tmp[pos]};
                    ans->push_back(nv);
                }
            }

        sort(ans->begin(), ans->end());
        auto ned = unique(ans->begin(), ans->end()) - ans->begin();
        auto sz = ans->size();
        for (int i = 1; i <= sz - ned; i++) ans->pop_back();
        cout << ned;

        return *ans;
    }
};

int main() { return 0; }