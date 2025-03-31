// Date   : 2025-04-05

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-04-05 11:32:59
 * @LastEditTime: Do not edit
 */

int maxProfit(vector<int> &prices) {
    int buy = INT_MAX, res = 0;
    for (int price : prices) {
        buy = min(buy, price);
        res = max(res, price - buy);
    }
    return res;
}