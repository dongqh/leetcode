// Date   : 2025-04-15

/**
 * @Solution 1: Dynamic Lists
 * @Time complexity: O(n)
 * @Space complexity: O(n)
 * @Date: 2025-04-15 11:38:35
 * @LastEditTime: Do not edit
 */

vector<int> pivotArray(vector<int> &nums, int pivot) {
    vector<int> less, equal, greater;
    for (int num : nums) {
        if (num < pivot) {
            less.push_back(num);
        } else if (num > pivot) {
            greater.push_back(num);
        } else {
            equal.push_back(num);
        }
    }
    less.insert(less.end(), equal.begin(), equal.end());
    less.insert(less.end(), greater.begin(), greater.end());
    return less;
}

// Todo more solution