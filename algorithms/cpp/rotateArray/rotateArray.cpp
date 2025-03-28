// Date   : 2025-03-28

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-03-28 10:02:39
 * @LastEditTime: Do not edit
 */

void rotate(vector<int> &nums, int k) {
    int n = nums.size(), realK = k % n;
    if (realK == 0) {
        return;
    }

    int i = 0, j = n - 1;
    while (i <= j) {
        swap(nums[i++], nums[j--]);
    }

    i = 0, j = realK - 1;
    while (i <= j) {
        swap(nums[i++], nums[j--]);
    }

    i = realK, j = n - 1;
    while (i <= j) {
        swap(nums[i++], nums[j--]);
    }
}