// Date   : 2025-04-15

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(n)
 * @Date: 2025-04-15 18:50:42
 */

vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
        m[nums[i]] = i;
    }

    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
        int tmp = target - nums[i];
        if (m.contains(tmp) && m[tmp] != i) {
            res.push_back(i);
            res.push_back(m[tmp]);
            break;
        }
    }
    return res;
}
