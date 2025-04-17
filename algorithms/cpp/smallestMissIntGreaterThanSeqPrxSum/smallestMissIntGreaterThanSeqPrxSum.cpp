// Date   : 2025-04-18

/**
 * @Solution 1:
 * @Time complexity: O(nlogn)
 * @Space complexity: O(1)
 * @Date: 2025-04-18 11:22:46
 */

int missingInteger(vector<int> &nums) {
    int sum = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] == nums[i - 1] + 1) {
            sum += nums[i];
        } else {
            break;
        }
    }
    sort(nums.begin(), nums.end());

    for (int num : nums) {
        if (sum == num) {
            ++sum;
        }
    }
    return sum;
}

// Todo more solution