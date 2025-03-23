// Date   : 2025-03-13
// Update : 2025-03-24

/**
 * Solution 1: 
 * Time complexity : O(n)
 * Space complexity: O(1)
 * 
*/

int missingNumber(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
        res ^= (i + 1) ^ nums[i];
    }
    return res;
}

/**
 * @Solution 2: Binary search
 *   If the array is sorted, binary search is also a good choice.
 * @Time complexity: O(nlog(n))
 * @Space complexity: O(log(n))
 * @Date: 2025-03-24 14:41:41
 */

 int missingNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > mid) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return right;
}

// Todo more solutions