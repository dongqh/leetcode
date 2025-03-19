// Date   : 2025-03-22

/**
 * Solution 1: Binary search
 * 
 * Time complexity : O(n*log(n))
 *   The number of iterations in binary search is O(logn),
 *   and each iteration takes  O(n) time.
 * Space complexity: O(1)
 *
**/

int findDuplicate(vector<int>& nums) {
    int left = 1, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2, count = 0;
        for (int num : nums) {
            if (num <= mid) {
                ++count;
            }
        }

        if (count <= mid) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return right;
}

// Todo more solution