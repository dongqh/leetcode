// Date   : 2025-03-17

/** 
 * Solution 1: depth-first search (DFS)
 * 
 * Time complexity : O(n)
 * Space complexity:
 *   The space complexity depends on the maximum size of the stack,
 *   which is determined by the tree's Height.
 *     O(height)=O(n) (worst case) or O(logn) (balanced case)
**/

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) {
        return false;
    }

    stack<TreeNode*> st{{root}};
    while (!st.empty()) {
        auto t = st.top();
        st.pop();
        if (t->val == targetSum && !t->left && !t->right) {
            return true;
        }

        if (t->right) {
            t->right->val += t->val;
            st.push(t->right);
        }

        if (t->left) {
            t->left->val += t->val;
            st.push(t->left);
        }
    }
    return false;
}

/** 
 * Solution 2:
 * 
 * Time complexity : O(n)
 * Space complexity: 
 *   The space cost depends on recursion depth:
 *    - Balanced binary tree: Height is O(log n), so space is O(log n).
 *    - Skewed tree (linked list-like): Height is O(n), so space is O(n)
**/

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) {
        return false;
    }

    if (root->val == targetSum && !root->left && !root->right) {
        return true;
    }

    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
}