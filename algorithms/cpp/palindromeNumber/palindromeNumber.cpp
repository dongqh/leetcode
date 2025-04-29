// Date   : 2025-05-02

/**
 * @Solution 1:
 * @Time complexity: O(logx)
 * @Space complexity: O(1)
 * @Date: 2025-05-02 16:08:05
 */

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    int div = 1;
    while (x / div >= 10) {
        div *= 10;
    }

    while (x > 0) {
        int left = x / div;
        int right = x % 10;
        if (left != right) {
            return false;
        }
        x = (x % div) / 10;
        div /= 100;
    }
    return true;
}

// Todo more solutions