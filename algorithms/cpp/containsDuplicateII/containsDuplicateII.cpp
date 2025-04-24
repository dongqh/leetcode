// Date   : 2025-04-24

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(n)
 * @Date: 2025-04-24 14:45:41
 */

bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
        if (m.contains(nums[i]) && i - m[nums[i]] <= k) {
            return true;
        } else {
            m[nums[i]] = i;
        }
    }
    return false;
}

// Todo more solution