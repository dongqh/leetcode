// Date   : 2025-03-08

/*
 * Solution 1: 
 * Time complexity : O(n^2)
 * Space complexity: O(n)
*/

int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    int res = 1;

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }

    return res;
}

// To do

/*
 * Solution 2
 * Time complexity : O(n*logn)
*/