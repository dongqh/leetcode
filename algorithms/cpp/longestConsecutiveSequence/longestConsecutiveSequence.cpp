// Date   : 2025-03-25

/**
 * @Solution 1: 
 * @Time complexity: O(n)
 * @Space complexity: O(n)
 * @Date: 2025-03-25 12:43:16
 * @LastEditTime:
 */

int longestConsecutive(vector<int>& nums) {
    int res = 0;
    unordered_set<int> st(nums.begin(), nums.end());
    for (int num : nums) {
        if (!st.contains(num)) {
            continue;
        }
        st.erase(num);
        int pre = num - 1, next = num + 1, count = 1;
        while (st.contains(pre)) {
            ++count;
            st.erase(pre--);
        }
        while (st.contains(next)) {
            ++count;
            st.erase(next++);
        }
        res = max(res, count);
    }
    return res;
}

/**
 * @Solution 2: Similar to solution 1, without using the variable 
 * @Time complexity: O(n)
 * @Space complexity: O(n)
 * @Date: 2025-03-25 13:02:50
 * @LastEditTime: 
 */

int longestConsecutive(vector<int>& nums) {
    int res = 0;
    unordered_set<int> st(nums.begin(), nums.end());
    for (int num : nums) {
        if (!st.contains(num)) {
            continue;
        }
        st.erase(num);
        int pre = num - 1, next = num + 1;
        while (st.contains(pre)) {
            st.erase(pre--);
        }
        while (st.contains(next)) {
            st.erase(next++);
        }
        res = max(res, next - pre - 1); // attention 'next-pre-1
    }
    return res;
}

// Todo more solution