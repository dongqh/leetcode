// Date   : 2025-04-29

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-04-29 14:37:37
 */

vector<int> findDuplicates(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != nums[nums[i] - 1]) {
            swap(nums[i], nums[nums[i] - 1]);
            --i; // why?
        }
    }
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != i + 1) {
            res.push_back(nums[i]);
        }
    }
    return res;
}

// Todo more solution