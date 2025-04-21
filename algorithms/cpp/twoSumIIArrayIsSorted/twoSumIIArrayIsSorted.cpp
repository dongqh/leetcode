// Date   : 2025-04-21

/**
 * @Solution 1: Binary search
 * @Time complexity: O(nlogn)
 * @Space complexity: O(1)
 * @Date: 2025-04-21 17:30:54
 */

vector<int> twoSum(vector<int> &numbers, int target) {
    for (int i = 0; i < numbers.size(); ++i) {
        int t = target - numbers[i];
        int left = i + 1, right = numbers.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (numbers[mid] == t) {
                return {i + 1, mid + 1};
            } else if (numbers[mid] < t) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
    }
    return {};
}

/**
 * @Solution 2: Two points
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-04-21 17:32:20
 */

vector<int> twoSum(vector<int> &numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            return {left + 1, right + 1};
        } else if (sum < target) {
            ++left;
        } else {
            --right;
        }
    }
    return {};
}
