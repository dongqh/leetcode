// Date   : 2025-03-26


/**
 * @Solution 1: 
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-03-26 09:32:21
 * 
 * Essential point:
 * The key idea is to use fast and slow pointers, where i acts as the fast pointer.
 * Initially, both pointers start at the first number. 
 * If the numbers at both pointers are the same, the fast pointer moves one step forward. 
 * If they are different, both pointers move one step forward.
 */

int removeDuplicates(vector<int>& nums) {
    int slow = 0, n = nums.size();
    for (int i = 0; i < n; ++i) {
        if (nums[i] != nums[slow]) {
            nums[++slow] = nums[i];
        }
    }
    return nums.empty() ? 0 : (slow + 1);
}

/**
 * @Solution 2:  
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-03-26 09:44:00
 * 
 * The essentail point is same to solution 1, but this one is easier to understand.
 */
int removeDuplicates(vector<int>& nums) {
    int n = nums.size(), slow = 0, fast = 0;
    while (fast < n) {
        if (nums[fast] != nums[slow]) {
            nums[++slow] = nums[fast++];
        } else {
            ++fast;
        }
    }
    return nums.empty() ? 0 : (slow + 1);
}

// Todo more solution