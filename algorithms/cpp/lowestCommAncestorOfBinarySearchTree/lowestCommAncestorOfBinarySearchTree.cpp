
/**
 * @Solution 1: Recursive solution
 * @Time complexity: O(h), h is the height of tree
 *   1) balance BST: O(logn)
 *   2) Degenerate BST(Linklist like): O(n)
 * @Space complexity: O(h), (Recursive stack)
 *   1) balance BST: O(logn)
 *   2) Degenerate BST(Linklist like): O(n)
 * @Date: 2025-04-23 15:10:26

 */

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root) {
        return root;
    }
    if (root->val > max(p->val, q->val)) {
        return lowestCommonAncestor(root->left, p, q);
    } else if (root->val < min(p->val, q->val)) {
        return lowestCommonAncestor(root->right, p, q);
    } else {
        return root;
    }
}

// Todo more solution: iterative