#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <cctype>
#include <queue>
#include <array>
#include <cstring>
#include <list>
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
//	Solution t;
//	cout << t.predictPartyVictory("RD") << endl;
	return 0;
}

