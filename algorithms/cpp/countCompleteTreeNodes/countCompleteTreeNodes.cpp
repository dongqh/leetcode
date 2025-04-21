// Date   : 2025-04-22

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity:
 *   O(log n)
 * @Date: 2025-04-22 16:07:20
 */

int countNodes(TreeNode *root) {
    if (!root) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Todo more solution
// Make use of the properties of a complete binary tree