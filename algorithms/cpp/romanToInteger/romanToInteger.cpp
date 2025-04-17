// Date   : 2025-04-19

/**
 * @Solution 1: Brute Solution
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-04-19 15:08:09
 */

int romanToInt(string s) {
    int res = 0, n = s.size();
    unordered_map<char, int> m{{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                               {'C', 100}, {'D', 500}, {'M', 1000}};
    for (int i = 0; i < n; ++i) {
        if (i + 1 < n) {
            if (s[i] == 'I') {
                if (s[i + 1] == 'V') {
                    res += 4;
                    ++i;
                } else if (s[i + 1] == 'X') {
                    res += 9;
                    ++i;
                } else {
                    res += 1;
                }
            } else if (s[i] == 'X') {
                if (s[i + 1] == 'L') {
                    res += 40;
                    ++i;
                } else if (s[i + 1] == 'C') {
                    res += 90;
                    ++i;
                } else {
                    res += 10;
                }
            } else if (s[i] == 'C') {
                if (s[i + 1] == 'D') {
                    res += 400;
                    ++i;
                } else if (s[i + 1] == 'M') {
                    res += 900;
                    ++i;
                } else {
                    res += 100;
                }
            } else {
                res += m[s[i]];
            }
        } else {
            res += m[s[i]];
        }
    }
    return res;
}

/**
 * @Solution 2:
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-04-19 15:11:47
 */

int romanToInt(string s) {
    int res = 0, n = s.size();
    unordered_map<char, int> m{{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                               {'C', 100}, {'D', 500}, {'M', 1000}};
    for (int i = 0; i < n; ++i) {
        if (i == n - 1 || m[s[i + 1]] <= m[s[i]]) {
            res += m[s[i]];
        } else {
            res -= m[s[i]];
        }
    }
    return res;
}
