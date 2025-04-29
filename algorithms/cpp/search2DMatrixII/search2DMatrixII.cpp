// Date   : 2025-04-29

/**
 * @Solution 1:
 *   This solution is basically the same as leetcode 74.
 * @Time complexity: O(m+n)
 * @Space complexity: O(1)
 * @Date: 2025-04-30 14:35:15
 */

bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.empty()) {
        return false;
    }
    if (target < matrix[0][0] || target > matrix.back().back()) {
        return false;
    }
    int i = 0, j = matrix[0].size() - 1;
    while (i < matrix.size() && j >= 0) {
        if (matrix[i][j] == target) {
            return true;
        } else if (matrix[i][j] > target) {
            --j;
        } else {
            ++i;
        }
    }
    return false;
}

//  Todo more solution