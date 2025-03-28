// Date   : 2025-03-28

/**
 * @Solution:
 * @Time complexity: O(m+n)
 *  Assume the length of ransomNote is m and the length of magazine is n.
 * @Space complexity: O(1)
 * @Date: 2025-03-28 09:42:22
 */

bool canConstruct(string ransomNote, string magazine) {
  unordered_map<char, int> m;
  for (auto c : magazine) {
    ++m[c];
  }

  for (auto c : ransomNote) {
    if (m[c] <= 0) {
      return false;
    } else {
      --m[c];
    }
  }
  return true;
}