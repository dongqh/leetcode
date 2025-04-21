// Date   : 2025-04-23

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(h), h is the height of tree
 *   1) Worst case (linked-list-like tree): O(n)
 *   2) Average/Best case (balanced binary tree): O(log⁡n)
 * @Date: 2025-04-23 14:41:54
 */

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root || root == p || root == q) {
        return root;
    }

    auto left = lowestCommonAncestor(root->left, p, q);
    auto right = lowestCommonAncestor(root->right, p, q);

    if (left && right) {
        return root;
    }

    return left ? left : right;
}

// Todo more solution, maybe iterative?
