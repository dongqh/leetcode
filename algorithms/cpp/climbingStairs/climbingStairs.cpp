// Date   : 2025-04-03

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(n)
 * @Date: 2025-04-03 15:12:12
 * @LastEditTime: Do not edit
 */

int climbStairs(int n) {
    int dp[n];
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n - 1];
}

// Todo more solutions