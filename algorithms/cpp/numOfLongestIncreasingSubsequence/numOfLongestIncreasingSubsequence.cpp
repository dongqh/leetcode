// Date   : 2025-03-09

/*
 * Solution 1: dynamic programming
 * Time complexity : O(n^2)
 * Space complexity: O(n)
*/

int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    // len[i] represents the length of the recurrence sequence ending with nums[i].
    vector<int> lens(n, 1);
    // cnt[i] represents the number of recurrence sequences ending with nums[i].
    vector<int> counts(n, 1);
    int maxLen = 0;
    int res = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] <= nums[j]) {
                continue;
            }
            if (lens[i] == lens[j] + 1) {
                counts[i] += counts[j];
            } else if (lens[i] < lens[j] + 1) {
                lens[i] = lens[j] + 1;
                counts[i] = counts[j];
            }
        }

        if (maxLen == lens[i]) {
            res += counts[i];
        } else if (maxLen < lens[i]) {
            maxLen = lens[i];
            res = counts[i];
        }
    }
    return res;
}