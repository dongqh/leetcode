// Date   : 2025-03-14

/**
 * Solution 1: 
 * 
 * If root has n nodes, and subRoot has m nodes.
 * 
 * Outer function — isSubtree()
 * - In the worst case, the algorithm compares subRoot against
 *  every node in the main tree root.  The function will call
 *  isSame() on each node — so there are O(n) calls to isSame().
 * 
 * For each node in root (n nodes), isSame() may run and
 *  compare up to m nodes in subRoot.
 * 
 * Time complexity : O(n×m)
 * 
 * The space cost comes mainly from recursion:
 *  - Height of the tree determines recursion depth.
 * Space complexity is:
 *   O(height of root)=O(n) (worst case)
 *     or O(logn) (balanced case)
 * Space complexity: O(n)
 * 
*/

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) {
        return false;
    }
    if (isSame(root, subRoot)) {
        return true;
    }

    return isSubtree(root->left, subRoot) ||
           isSubtree(root->right, subRoot);
}

bool isSame(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
        return true;
    }
    if (p && !q || !p && q || p->val != q->val) {
        return false;
    }

    return isSame(p->left, q->left) && isSame(p->right, q->right);
}