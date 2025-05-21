// Date   : 2025-06-20

// Tag: Greedy, Array

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(n)
 * @Date: 2025-06-20 14:46:40
 */

int candy(vector<int> &ratings) {
    int res = 0, n = ratings.size();
    vector<int> nums(n, 1);

    for (int i = 0; i < n - 1; ++i) {
        if (ratings[i] < ratings[i + 1]) {
            nums[i + 1] = nums[i] + 1;
        }
    }

    for (int i = n - 1; i > 0; --i) {
        if (ratings[i - 1] > ratings[i]) {
            nums[i - 1] = max(nums[i - 1], nums[i] + 1);
        }
    }

    for (int num : nums) {
        res += num;
    }

    return res;
}

// Todo more solution