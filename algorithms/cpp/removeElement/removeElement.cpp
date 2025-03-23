// Date   : 2025-03-26

/**
 * @Solution: 
 * @Time complexity: 
 * @Space complexity: 
 * @Date: 2025-03-26 11:00:06
 * 
 * Key point:
 * You only need one variable to count.
 * Then, traverse the original array — if the current value 
 * is different from the given value, overwrite the position
 * of the count variable with the current value and increment the count variable by 1.
 */

int removeElement(vector<int>& nums, int val) {
    int res = 0, n = nums.size();
    for (int i = 0; i < n; ++i) {
        if (nums[i] != val) {
            nums[res++] = nums[i];
        }
    }
    return res;
}