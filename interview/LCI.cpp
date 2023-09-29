// https://leetcode.cn/problems/longest-increasing-subsequence/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp;
		for (int i = 0; i < n; i++) {
			int cur = nums[i];
			auto pos = lower_bound(dp.begin(), dp.end(), cur);
			if (pos != dp.end()) {
				*pos = cur;
			} else {
				dp.push_back(cur);
			}
		}
		return dp.size();
    }
};

int main() {

	return 0;
}

