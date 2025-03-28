// Date   : 2025-03-29

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(n)
 *  The main space consumption comes from the stack st,
 * which in the worst case stores O(n) integers.
 * @Date: 2025-03-29 15:26:48
 */

int evalRPN(vector<string> &tokens) {
    unordered_set<string> symbol{"+", "-", "*", "/"};
    stack<int> st;

    for (auto &str : tokens) {
        if (!symbol.contains(str)) {
            st.push(stoi(str));
        } else {
            if (st.size() < 2) {
                return -1;
            }
            auto second = st.top();
            st.pop();
            auto first = st.top();
            st.pop();

            if (str == "+") {
                st.push(first + second);
            } else if (str == "-") {
                st.push(first - second);
            } else if (str == "*") {
                st.push(first * second);
            } else if (str == "/") {
                st.push(first / second);
            }
        }
    }
    return st.top();
}

// Todo more solution: recursion solution