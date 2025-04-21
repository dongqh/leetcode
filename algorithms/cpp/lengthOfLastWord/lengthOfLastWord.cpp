// Date   : 2025-04-24

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-04-24 09:35:32
 */

int lengthOfLastWord(string s) {
    int right = s.size() - 1, res = 0;
    while (right >= 0 && s[right] == ' ') {
        --right;
    }
    while (right >= 0 && s[right--] != ' ') {
        ++res;
    }
    return res;
}

// Todo more solution
