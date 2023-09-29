// https://leetcode.cn/problems/edit-distance/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string a, string b) {
		int n = a.size();
		int m = b.size();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1));

		for (int i = 1; i <= n; i++)
			dp[i][0] = i;
		for (int j = 1; j <= m; j++)
			dp[0][j] = j;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i - 1] == b[j - 1] ? 0 : 1));
			}
		return dp[n][m];
    }
};


int main() {

	return 0;
}

