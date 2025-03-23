// Date   : 2025-03-23

/**
 * @Solution 1: 
 * @Time complexity: O(n)
 * @Space complexity: O(n)
 * @Date: 2025-03-23 13:40:49
 */

 int sumOfUnique(vector<int>& nums) {
    unordered_map<int, int> m;
    for (int num : nums) {
        ++m[num];
    }

    int sum{0};
    for (auto& t : m) {
        if (t.second == 1) {
            sum += t.first;
        }
    }
    return sum;
}

/**
 * @Solution 2: 
 *  Since the maximum length of the array is 100,
 *  a fixed-length array can be used.
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-03-23 13:42:42
 */

 int sumOfUnique(vector<int>& nums) {
    int counts[101];
    for (int num : nums) {
        ++counts[num];
    }
    int res = 0;
    for (int i = 1; i < 101; ++i) {
        if (counts[i] == 1) {
            res += i;
        }
    }

    return res;
}