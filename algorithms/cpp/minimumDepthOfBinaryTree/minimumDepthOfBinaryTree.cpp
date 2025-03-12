// Date   : 2025-03-11

/*
 * Solution 1: Iterative Solution (BFS)
 * Time complexity : O(n)
 * Space complexity: 
 *   1) Worst case: O(n)
 *   2) In general, the time complexity is approximately O(W),
 *  where W is the maximum width of the tree.
 * 
*/

int minDepth(TreeNode* root) {
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
            if (!t->left && !t->right) {
                return res;
            }
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

int minDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    if (!root->left) {
        return 1 + minDepth(root->right);
    }
    if (!root->right) {
        return 1 + minDepth(root->left);
    }

    return 1 + min(minDepth(root->left), minDepth(root->right));
}