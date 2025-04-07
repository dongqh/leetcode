// Date   : 2025-04-07

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-04-07 14:36:47
 */

bool canJump(vector<int> &nums) {
    int n = nums.size(), reach = 0;
    for (int i = 0; i < n; ++i) {
        if (i > reach || reach >= n - 1) {
            break;
        }
        reach = max(reach, i + nums[i]);
    }
    return reach >= n - 1;
}