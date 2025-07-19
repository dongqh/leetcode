// Date   : 2025-08-10

/******************************************************************************************************
 * Seven different symbols represent Roman numerals with the following values:
 *
 * Symbol	Value
 *  I	     1
 *  V	     5
 *  X	     10
 *  L	     50
 *  C	     100
 *  D	     500
 *  M	     1000
 *
 * Roman numerals are formed by appending the conversions of decimal place
 *values from highest to lowest. Converting a decimal place value into a Roman
 *numeral has the following rules:
 *  * If the value does not start with 4 or 9, select the symbol of the maximal
 *value that can be subtracted from the input, append that symbol to the result,
 *subtract its value, and convert the remainder to a Roman numeral.
 *  * If the value starts with 4 or 9 use the subtractive form representing one
 *symbol subtracted from the following symbol, for example, 4 is 1 (I) less than
 *5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive
 *forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
 *  * Only powers of 10 (I, X, C, M) can be appended consecutively at most 3
 *times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500
 *(D) multiple times. If you need to append a symbol 4 times use the subtractive
 *form.
 *
 * Given an integer, convert it to a Roman numeral.
 *
 * Example 1:
 *   Input: num = 3749
 *   Output: "MMMDCCXLIX"
 *
 * Example 2:
 *   Input: num = 58
 *   Output: "LVIII"
 *
 * Example 3:
 *   Input: num = 1994
 *   Output: "MCMXCIV"
 *
 * Constraints:
 *   1 <= num <= 3999
 ******************************************************************************************************/

/**
 * @Solution 1:
 * @Time complexity: O(1)
 *   The loop runs a fixed number of iterations regardless of input size.
 * @Space complexity: O(1)
 *   Uses a fixed number of auxiliary variables and vectors.
 * @Date: 2025-08-10 16:24:59
 */

#include <string>
#include <vector>
using namespace std;

string intToRoman(int num) {
    string res{};
    vector<char> roman{'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    vector<int> numeral{1000, 500, 100, 50, 10, 5, 1};

    for (int i = 0; i < 7; i += 2) { // attention
        int x = num / numeral[i];
        if (x < 4) {
            for (int j = 0; j < x; ++j) {
                res += roman[i];
            }
        } else if (x == 4) {
            res = res + roman[i] + roman[i - 1];
        } else if (x > 4 && x < 9) {
            res += roman[i - 1];
            for (int j = 5; j < x; ++j) {
                res += roman[i];
            }
        } else if (x == 9) {
            res = res + roman[i] + roman[i - 2]; // attention
        }

        num %= numeral[i];
    }
    return res;
}
