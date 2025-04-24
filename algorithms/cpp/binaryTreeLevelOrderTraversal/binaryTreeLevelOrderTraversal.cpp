// Date   : 2025-04-27

/**
 * @Solution 1: Iterative
 * @Time complexity: O(n)
 * @Space complexity: O(n)
 * @Date: 2025-04-27 10:13:38
 */

vector<vector<int>> levelOrder(TreeNode *root) {
    if (!root) {
        return {};
    }
    vector<vector<int>> res;
    queue<TreeNode *> q{{root}};
    while (!q.empty()) {
        vector<int> line;
        for (int i = q.size(); i > 0; --i) {
            auto p = q.front();
            q.pop();
            line.push_back(p->val);
            if (p->left) {
                q.push(p->left);
            }
            if (p->right) {
                q.push(p->right);
            }
        }
        res.push_back(line);
    }
    return res;
}

/**
 * @Solution 2: Recursive
 * @Time complexity: O(n)
 * @Space complexity: O(n)
 * @Date: 2025-04-27 10:25:21
 */

vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    levelOrder(root, 0, res);
    return res;
}

void levelOrder(TreeNode *root, int level, vector<vector<int>> &res) {
    if (!root) {
        return;
    }
    if (res.size() == level)
        res.push_back({});
    res[level].push_back(root->val);
    if (root->left)
        levelOrder(root->left, level + 1, res);
    if (root->right)
        levelOrder(root->right, level + 1, res);
}
