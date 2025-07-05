// Date   : 2025-03-13

/******************************************************************************************************
 *
 * Given a non-empty array of integers nums, every element appears twice except
 *for one. Find that single one.
 *
 * You must implement a solution with a linear runtime complexity and use only
 *constant extra space.
 *
 *
 * Example 1:
 *  Input: nums = [2,2,1]
 *  Output: 1
 *
 * Example 2:
 *  Input: nums = [4,1,2,1,2]
 *  Output: 4
 *
 * Example 3:
 *  Input: nums = [1]
 *  Output: 1
 *
 * Constraints:
 *  - Each element in the array appears twice except for one element which
 *appears only once.
 ******************************************************************************************************/
/**
 * Solution 1:
 * Time complexity : O(n)
 * Space complexity: O(1)
 *
 */

int singleNumber(vector<int> &nums) {
    unordered_set<int> res;
    for (int num : nums) {

        if (res.contains(num)) {
            res.erase(num);
        } else {
            res.insert(num);
        }
    }

    return *res.begin();
}

/**
 * Solution 2:
 *
 * Time complexity : O(n)
 * Space complexity: O(1)
 **/

int singleNumber(vector<int> &nums) {
    int res = 0;
    for (int num : nums) {
        res ^= num;
    }
    return res;
}