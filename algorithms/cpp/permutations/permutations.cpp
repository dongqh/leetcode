// Date   : 2025-04-08

/**
 * @Solution 1: DFS + Backtracking
 * @Time complexity: O(n * n!)
 * @Space complexity: O(n * n!)
 * @Date: 2025-04-08 15:56:19
 * @LastEditTime: Do not edit
 */

vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;
    dfs(nums, 0, res);
    return res;
}

void dfs(vector<int> &nums, int start, vector<vector<int>> &res) {
    if (start >= nums.size()) {
        res.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); ++i) {
        swap(nums[i], nums[start]);
        dfs(nums, start + 1, res);
        swap(nums[i], nums[start]);
    }
}

// Todo more solution
// - Brute-force solution
// - Iteration solution