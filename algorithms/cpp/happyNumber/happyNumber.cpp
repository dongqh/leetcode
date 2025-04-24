// Date   : 2025-04-25

/**
 * @Solution 1:
 * @Time complexity: O(logn)
 * @Space complexity: O(1)
 * @Date: 2025-04-25 10:06:40
 */

bool isHappy(int n) {
    unordered_set<int> s;
    while (n != 1) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }
        n = sum;
        if (s.contains(n)) {
            break;
        }
        s.insert(n);
    }
    return n == 1;
}