// Date   : 2025-04-29

/**
 * @Solution 1:
 * @Time complexity: O(m+n)
 *   m is line of matrix
 *   n is column of matrix
 * @Space complexity: O(1)
 * @Date: 2025-04-30 11:17:18
 */

bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.empty()) {
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

//  Todo more solution: binary search