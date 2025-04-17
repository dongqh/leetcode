// Date   : 2025-04-17

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(n)
 * @Date: 2025-04-17 14:44:32
 */

int kthSmallest(TreeNode *root, int k) {
    vector<int> res;
    stack<TreeNode *> st;
    auto p = root;
    while (p || !st.empty()) {
        if (p) {
            st.push(p);
            p = p->left;
        } else {
            p = st.top();
            st.pop();
            res.push_back(p->val);
            p = p->right;
        }
    }

    return res.at(k - 1);
}

/**
 * @Solution 2:
 * @Time complexity:  O(h + k)
 * h is the heigth of tree
 * k is the input param
 * @Space complexity: O(h)
 *  1) Worst case (linked-list-like tree): O(n)
 *  2) Average/Best case (balanced binary tree): O(log⁡n)
 * @Date: 2025-04-17 14:53:41
 */

int kthSmallest(TreeNode *root, int k) {
    stack<TreeNode *> st;
    int count = 0;
    auto p = root;
    while (p || !st.empty()) {
        if (p) {
            st.push(p);
            p = p->left;
        } else {
            p = st.top();
            st.pop();

            if (++count == k) {
                return p->val;
            }
            p = p->right;
        }
    }
    return 0;
}

// Todo more solution: recursive