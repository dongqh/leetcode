// Date   : 2025-06-07

/**
 * @Solution 1:
 * @Time complexity: O(mn)
 * @Space complexity: O(1)
 * @Date: 2025-06-07 16:13:59
 */

int strStr(string haystack, string needle) {
    if (needle.empty()) {
        return 0;
    }
    int m = haystack.size(), n = needle.size();
    if (m < n) {
        return -1;
    }

    for (int i = 0; i <= m - n; ++i) { // attention i<=m-n
        int j = 0;
        for (; j < n; ++j) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == n) {
            return i;
        }
    }
    return -1;
}

// Todo more solution
