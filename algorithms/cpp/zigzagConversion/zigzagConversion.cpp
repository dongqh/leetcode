// Date   : 2025-07-17

/******************************************************************************************************
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 *of rows like this: (you may want to display this pattern in a fixed font for
 *better legibility)
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a
 *number of rows: string convert(string s, int numRows);
 *
 * Example 1:
 *   Input: s = "PAYPALISHIRING", numRows = 3
 *   Output: "PAHNAPLSIIGYIR"
 *   Explanation:
 *   P   A   H   N
 *   A P L S I I G
 *   Y   I   R
 *
 * Example 2:
 *   Input: s = "PAYPALISHIRING", numRows = 4
 *   Output: "PINALSIGYAHRPI"
 *   Explanation:
 *   P     I    N
 *   A   L S  I G
 *   Y A   H R
 *   P     I
 *
 * Constraints:
 *  1. 1 <= s.length <= 1000
 *  2. s consists of English letters (lower-case and upper-case), ',' and '.'.
 *  3. 1 <= numRows <= 1000
 ******************************************************************************************************/

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(n)
 * @Date: 2025-07-17 11:06:09
 */

#include <string>
#include <vector>

using namespace std;

string convert(string s, int numRows) {
    if (numRows <= 1) {
        return s;
    }
    string res;
    vector<string> vec(numRows);
    int i = 0, n = s.size();

    while (i < n) {
        for (int pos = 0; pos < numRows && i < n; ++pos) {
            vec[pos] += s[i++];
        }
        for (int pos = numRows - 2; pos > 0 && i < n; --pos) {
            vec[pos] += s[i++];
        }
    }

    for (auto &s : vec) {
        res += s;
    }
    return res;
}