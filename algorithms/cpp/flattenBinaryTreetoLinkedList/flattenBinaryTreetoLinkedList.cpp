// Date   : 2025-07-05

/*********************************************************************************
 * Given the root of a binary tree, flatten the tree into a "linked list":
 *
 * - The "linked list" should use the same TreeNode class where the right child
 *pointer points to the next node in the list and the left child pointer is
 *always null.
 * - The "linked list" should be in the same order as a pre-order traversal of
 *the binary tree.
 *
 * Follow up: Can you flatten the tree in-place (with O(1) extra space)?
 **********************************************************************************/

/**
 * @Solution 1: Preorder
 * @Time complexity: O(n)
 * @Space complexity:
 *  In general: O(log n)
 *  Worst: O(n)
 * @Date: 2025-07-05 15:46:08
 */

void flatten(TreeNode *root) {
    if (!root) {
        return;
    }
    stack<TreeNode *> st{{root}};

    while (!st.empty()) {
        auto t = st.top();
        st.pop();
        if (t->left) {
            auto r = t->left;
            while (r->right) {
                r = r->right;
            }
            r->right = t->right;
            t->right = t->left;
            t->left = nullptr;
        }

        if (t->right) {
            st.push(t->right);
        }
    }
    return;
}

// Todo more solution