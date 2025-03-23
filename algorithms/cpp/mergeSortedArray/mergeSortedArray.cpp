// Date   : 2025-03-25

/**
 * @Solution 1: 
 *   Key point: Start assigning and moving from the end of the array.
 * @Time complexity: O(m+n)
 * @Space complexity: O(1)
 * @Date: 2025-03-25 16:21:27
 */
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}
