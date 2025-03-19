// Date   : 2025-03-21

/** 
 * Solution 1: Horizontal scanning
 * 
 * Time complexity : O(n × m)
 *   n is the number of strings,
 *   and m is the length of the longest common prefix.
 * Space complexity: O(m)
 *   The space required to store the result string.
 *   
**/

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
        return {};
    }

    string res = strs.front();
    for (auto& str : strs) {
        int len = min(res.size(), str.size());
        res = res.substr(0, len);
        for (int i = 0; i < len; ++i) {
            if (*(res.begin() + i) != *(str.begin() + i)) {
                res = res.substr(0, i);
            }
        }
    }
    return res;
}

/** 
 * Solution 2: vertical scanning
 * 
 * Time complexity : O(n × m)
 *   - The outer loop traverses the characters of strs[0],
 *     running at most m times (where m is the length of the first string).
 *   - The inner loop traverses the entire string array strs,
 *     running at most n times each time (where n is the size of the string array).
 * Space complexity: O(m)
 *   The space required to store the result string.
 *   
**/

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
        return {};
    }

    string res{};
    for (int j = 0; j < strs[0].size(); ++j) {
        char c = strs[0][j];
        for (int i = 0; i < strs.size(); ++i) {
            if (j >= strs[i].size() || strs[i][j] != c) {
                return res;
            }
        }
        res.push_back(c);
    }

    return res;
}

// Todo more solution
//  - Tire tree
//  - binary search