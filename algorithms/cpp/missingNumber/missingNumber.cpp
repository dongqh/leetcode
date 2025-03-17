// Date   : 2025-03-13

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

// Todo more solutions