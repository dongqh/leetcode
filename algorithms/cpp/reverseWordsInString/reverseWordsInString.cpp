// Date   : 2025-04-22

/**
 * @Solution:
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-04-22 12:39:42
 */

string reverseWords(string s) {
    int n = s.size(), index = 0;
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; ++i) {
        if (s[i] != ' ') {
            if (index != 0) {
                s[index++] = ' ';
            }
            int j = i;
            while (j < n && s[j] != ' ') {
                s[index++] = s[j++];
            }
            reverse(s.begin() + index - (j - i), s.begin() + index);
            i = j;
        }
    }
    s.resize(index);
    return s;
}

/**
 * @Solution 2:
 * @Time complexity: O(n^2)
 *   1) while(i < n):
 *      O(n)
 *   2) s.substr(i, j - i)
 *      O(k), (k = j - i)
 *   3) res = s.substr(...) + " " + res
 *      For m words, since we prepend new content each time,
 *      the actual complexity becomes:
 *       O(k) + O(2k) + O(3k) + ... + O(mk) = O(m²k)
 * @Space complexity: O(n)
 * @Date: 2025-04-22 13:02:40
 */

string reverseWords(string s) {
    string res;
    int n = s.size(), i = 0;
    while (i < n) {
        while (i < n && s[i] == ' ') {
            ++i;
        }
        if (i >= n) {
            break;
        }
        int j = i;
        while (j < n && s[j] != ' ') {
            ++j;
        }

        if (res.empty()) {
            res = s.substr(i, j - i);
        } else {
            res = s.substr(i, j - i) + " " + res;
        }

        i = j + 1;
    }
    return res;
}

// Todo more solution