// Date   : 2025-04-29

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-04-29 10:06:38
 */

int minSubArrayLen(int target, vector<int> &nums) {
    int left = 0, right = 0, len = nums.size(), res = len + 1, sum = 0;
    while (right < len) {
        while (sum < target && right < len) {
            sum += nums[right++];
        }
        while (sum >= target) {
            res = min(res, right - left);
            sum -= nums[left++];
        }
    }
    return res == len + 1 ? 0 : res;
}

// Todo more solution