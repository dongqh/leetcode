// Date   : 2025-04-09

/**
 * @Solution 1:
 * @Time complexity:
 * @Space complexity:
 * @Date: 2025-04-09 19:01:36
 * @LastEditTime: Do not edit
 */

bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (!isAlphaNum(s[left])) {
            ++left;
        } else if (!isAlphaNum(s[right])) {
            --right;
        } else if ((s[left++] + 32 - 'a') % 32 !=
                   (s[right--] + 32 - 'a') % 32) {
            return false;
        }
    }
    return true;
}

bool isAlphaNum(char c) {
    if (c >= 'a' && c <= 'z') {
        return true;
    }
    if (c >= 'A' && c <= 'Z') {
        return true;
    }
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}