// Date   : 2025-04-03

/**
 * @Solution 1: Recursive Solution
 * @Time complexity: O(n)
 * @Space complexity:
 *  1) Worst case (linked-list-like tree): O(N)
 *  2) Average/Best case (balanced binary tree): O(log⁡N)
 * @Date: 2025-04-03 11:11:57
 * @LastEditTime: Do not edit
 */

bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q) {
        return true;
    }
    if (p && !q || !p && q || p->val != q->val) {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

/**
 * @Solution 2: Iterative Solution
 * @Time complexity: O(n)
 * @Space complexity:
 *  1) Worst case (linked-list-like tree): O(N)
 *  2) Average/Best case (balanced binary tree): O(log⁡N)
 * @Date: 2025-04-03 13:10:45
 * @LastEditTime: Do not edit
 */

bool isSameTree(TreeNode *p, TreeNode *q) {
    stack<TreeNode *> st{{p, q}};
    while (!st.empty()) {
        p = st.top();
        st.pop();
        q = st.top();
        st.pop();
        if (!p && !q) {
            continue;
        }
        if (p && !q || !p && q || p->val != q->val) {
            return false;
        }

        st.push(p->right);
        st.push(q->right);

        st.push(p->left);
        st.push(q->left);
    }
    return true;
}