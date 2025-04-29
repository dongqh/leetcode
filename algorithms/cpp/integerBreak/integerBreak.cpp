// Date   : 2025-05-03

/**
 * @Solution 1: dynamic programming
 * @Time complexity: O(n^2)
 * @Space complexity: O(n)
 * @Date: 2025-05-03 21:48:45
 */

int integerBreak(int n) {
    vector<int> dp(n + 1, 1);
    for (int i = 3; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j])); // more think
        }
    }
    return dp[n];
}

// Todo more solution