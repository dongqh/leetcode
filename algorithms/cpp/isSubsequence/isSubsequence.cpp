// Date   : 2025-04-14

/**
 * @Solution 1:
 * @Time complexity: O(n)
 *  n = t.size()
 * @Space complexity: O(1)
 * @Date: 2025-04-14 09:34:42
 * @LastEditTime: Do not edit
 */

bool isSubsequence(string s, string t) {
    int m = s.size(), i = 0, n = t.size(), j = 0;
    while (i < m && j < n) {
        if (t[j] == s[i]) {
            ++i;
            ++j;
        } else {
            ++j;
        }
    }

    return (i == m) ? true : false;
}

/**
 * @Solution 2:
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-04-14 10:05:39
 * @LastEditTime: Do not edit
 */

bool isSubsequence(string s, string t) {
    int i = 0;
    for (int j = 0; i < s.size() && j < t.size(); ++j) {
        if (s[i] == t[j]) {
            ++i;
        }
    }
    return i == s.size();
}