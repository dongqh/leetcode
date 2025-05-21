// Date   : 2025-06-20

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity:
 * avarage O(log n)
 * worst O(n)
 * @Date: 2025-06-20 23:13:54
 */
int getMinimumDifference(TreeNode *root) {
    int res = INT_MAX, pre = -1;
    inorder(root, res, pre);
    return res;
}

void inorder(TreeNode *root, int &res, int &pre) {
    if (!root) {
        return;
    }
    inorder(root->left, res, pre);
    if (pre != -1) {
        res = min(res, root->val - pre);
    }
    pre = root->val;
    inorder(root->right, res, pre);
}

/**
 * @Solution 2:
 * @Time complexity: O(n)
 * @Space complexity:
 * avarage O(log n)
 * worst O(n)
 * @Date: 2025-06-21 00:49:09
 */
int getMinimumDifference(TreeNode *root) {
    int res = INT_MAX, pre = -1;
    stack<TreeNode *> st;
    TreeNode *p = root;
    while (p || !st.empty()) {
        while (p) {
            st.push(p);
            p = p->left;
        }

        p = st.top();
        st.pop();
        if (pre != -1) {
            res = min(res, p->val - pre);
        }
        pre = p->val;
        p = p->right;
    }
    return res;
}