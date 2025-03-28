// Date   : 2025-03-28

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(n)
 * @Date: 2025-03-28 15:50:44
 */

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) {
                return false;
            }
            auto ch = st.top();
            if (ch == '(' && c == ')') {
                st.pop();
            } else if (ch == '[' && c == ']') {
                st.pop();
            } else if (ch == '{' && c == '}') {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty() ? true : false;
}

// It can be written more concisely.