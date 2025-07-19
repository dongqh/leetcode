// Date   : 2025-07-20

/******************************************************************************************************
 * Given the root of a binary tree, imagine yourself standing on the right side
 *of it, return the values of the nodes you can see ordered from top to bottom.
 *
 * Example 1:
 *   Input: root = [1,2,3,null,5,null,4]
 *   Output: [1,3,4]
 *
 * Example 2:
 *   Input: root = [1,2,3,4,null,null,null,5]
 *   Output: [1,3,4,5]
 ******************************************************************************************************/

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity:
 *   worest case: O(n)
 * @Date: 2025-07-20 10:10:46
 */

vector<int> rightSideView(TreeNode *root) {
    if (!root) {
        return {};
    }
    vector<int> res;
    queue<TreeNode *> q{{root}};

    while (!q.empty()) {
        res.push_back(q.back()->val);
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