// Date   : 2025-04-17

/**
 * @Solution 1: dynamic programming
 * @Time complexity: O(n)
 * @Space complexity: O(n)
 * @Date: 2025-04-17 09:27:38
 */

int trap(vector<int> &height) {
    int res = 0, mx = 0, n = height.size();
    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) {
        dp[i] = mx;
        mx = max(mx, height[i]);
    }
    mx = 0;
    for (int i = n - 1; i >= 0; --i) {
        dp[i] = min(mx, dp[i]);
        mx = max(mx, height[i]);
        if (height[i] < dp[i]) {
            res += dp[i] - height[i];
        }
    }
    return res;
}

/**
 * @Solution 2: stack
 * @Time complexity: O(n)
 * @Space complexity: O(n)
 * @Date: 2025-04-17 10:27:10
 */

int trap(vector<int> &height) {
    int res = 0, i = 0, n = height.size();
    stack<int> st;
    while (i < n) {
        if (st.empty() || height[st.top()] > height[i]) {
            st.push(i++);
        } else {
            auto t = st.top();
            st.pop();
            if (st.empty()) {
                continue;
            } else {
                // more think
                res += (min(height[st.top()], height[i]) - height[t]) *
                       (i - st.top() - 1);
            }
        }
    }
    return res;
}

// Todo more solution. eg: two points