// Date   : 2025-05-03

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-05-03 14:13:18
 */

int findMin(vector<int> &nums) {
    if (nums[0] <= nums.back()) {
        return nums[0];
    }

    for (int num : nums) {
        if (num < nums[0]) {
            return num;
        }
    }

    return -1;
}

/**
 * @Solution 2:
 * @Time complexity: O(logn)
 * @Space complexity: O(1)
 * @Date: 2025-05-03 14:14:00
 */

int findMin(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return nums[right];
}

//  Todo more solution