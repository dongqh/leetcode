// Date   : 2025-04-07

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-04-07 09:20:20
 * @LastEditTime: Do not edit
 */

int maxProfit(vector<int> &prices) {
    int res = 0, n = prices.size();
    for (int i = 0; i < n - 1; ++i) {
        if (prices[i] < prices[i + 1]) {
            res += prices[i + 1] - prices[i];
        }
    }
    return res;
}