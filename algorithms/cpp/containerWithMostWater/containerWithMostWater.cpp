// Date   : 2025-04-28

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-04-28 14:33:40
 */

int maxArea(vector<int> &height) {
    int left = 0, right = height.size() - 1, res = 0;
    while (left < right) {
        res = max(res, min(height[left], height[right]) * (right - left));
        height[left] < height[right] ? ++left : --right;
    }
    return res;
}
