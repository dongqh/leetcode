// Date   : 2025-04-21

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(n)
 * @Date: 2025-04-21 14:31:08
 */

vector<string> summaryRanges(vector<int> &nums) {
    vector<string> res;
    int n = nums.size(), i = 0;
    while (i < n) {
        int j = 1;
        while (i + j < n && nums[i + j] == nums[i] + j) {
            ++j;
        }
        if (j <= 1) {
            res.push_back(to_string(nums[i]));
        } else {
            res.push_back(to_string(nums[i]) + "->" +
                          to_string(nums[i + j - 1]));
        }
        i += j;
    }
    return res;
}
