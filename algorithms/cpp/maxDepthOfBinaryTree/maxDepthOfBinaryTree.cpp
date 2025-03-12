// Date   : 2025-03-11

/******************************************************************************************************
 * Given the root of a binary tree, return its maximum depth.
 * A binary tree's maximum depth is the number of nodes along the longest path from the root node down
 *  to the farthest leaf node.
 * 
******************************************************************************************************/

/*
 * Solution 1: Iterative Solution (BFS)
 * Time complexity : O(n)
 * Space complexity: 
 *   1) Worst case: O(n)
 *   2) In general, the time complexity is approximately O(W),
 *  where W is the maximum width of the tree.
 * 
*/

int maxDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int res = 0;
    queue<TreeNode*> q{{root}};
    while (!q.empty()) {
        ++res;
        for (int i = q.size(); i > 0; --i) {
            auto t = q.front();
            q.pop();
            if (t->left) {
                q.push(t->left);
            }
            if (t->right) {
                q.push(t->right);
            }
        }
    }
    return res;
}

/*
 * Solution 2: Recursive Solution
 * Time complexity : O(n)
 * Space complexity: 
 *  1) Worst case (linked-list-like tree): O(N)
 *  2) Average/Best case (balanced binary tree): O(log⁡N)
 * 
*/

int maxDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}