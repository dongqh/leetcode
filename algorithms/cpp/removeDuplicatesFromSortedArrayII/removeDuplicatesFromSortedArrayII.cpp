// Date   : 2025-03-27

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-03-27 10:52:10
 */

int removeDuplicates(vector<int> &nums) {
  int slow = 0, fast = 1, cnt = 1, n = nums.size();
  while (fast < n) {
    if (nums[slow] == nums[fast] && cnt == 0) {
      ++fast;
    } else {
      if (nums[slow] == nums[fast]) {
        --cnt;
      } else {
        cnt = 1;
      }
      nums[++slow] = nums[fast++];
    }
  }
  return nums.empty() ? 0 : slow + 1;
}

/**
 * @Solution 2:
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-03-27 11:18:17
 */

int removeDuplicates(vector<int> &nums) {
  int i = 0;
  for (int num : nums) {
    if (i < 2 || num > nums[i - 2]) {
      nums[i++] = num;
    }
  }
  return i;
}