// https://leetcode.cn/problems/qJnOS7/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));

		// dp[i][j] - LCS length of a[1:i] and b[1:j]
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (a[i - 1] == b[j - 1] ? 1 : 0));
			}
            return dp[n][m];
    }
};

int main() {

	return 0;
}

