// Date   : 2025-06-21

//  Tag: Array, Two point, Sort

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-06-21 11:53:09
 */

vector<int> sortArrayByParityII(vector<int> &nums) {
    int i = 0, j = 1, n = nums.size();
    while (i < n && j < n) {
        if (nums[i] % 2 == 0) {
            i += 2;
        } else if (nums[j] % 2 == 1) {
            j += 2;
        } else {
            swap(nums[i], nums[j]);
        }
    }

    return nums;
}

/**
 * @Solution 2:
 * @Time complexity: O(n)
 * @Space complexity: O(n)
 * @Date: 2025-06-21 12:03:11
 */

vector<int> sortArrayByParityII(vector<int> &nums) {
    vector<int> odds, evens, res;
    for (int num : nums) {
        if (num % 2 == 0) {
            evens.push_back(num);
        } else {
            odds.push_back(num);
        }
    }

    for (int i = 0; i < evens.size(); ++i) {
        res.push_back(evens[i]);
        res.push_back(odds[i]);
    }

    return res;
}
