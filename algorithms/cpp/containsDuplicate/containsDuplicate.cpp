// Date   : 2025-04-24

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(n)
 * @Date: 2025-04-24 14:38:39
 */

bool containsDuplicate(vector<int> &nums) {
    unordered_set<int> s;
    for (int num : nums) {
        if (s.contains(num)) {
            return true;
        }
        s.insert(num);
    }
    return false;
}

// Todo more solution: use sort method