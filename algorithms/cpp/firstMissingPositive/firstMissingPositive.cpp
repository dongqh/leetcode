// Date   : 2025-03-22

/** 
 * Solution 1: Cycle sort
 * 
 * Time complexity : O(n)
 *   Each number is processed once,
 *   and each swap corrects one number’s position, ensuring a linear time.
 * Space complexity: O(1)
 *   
**/

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        while (nums[i] > 0 && nums[i] <= n &&
               nums[nums[i] - 1] != nums[i]) {
            swap(nums[nums[i] - 1], nums[i]);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return n + 1;
}

// Todo more solution: Editoral from leetcode at least.