// Date   : 2025-03-18

/** 
 * Solution 1: DFS
 * 
 * Time complexity :
 * Part 1. Each node is visited once, with one push (line.push_back) 
 *   and one pop (line.pop_back). The total time for these operations is O(n)
 * Part 2. When reaching a leaf node, if the path sum equals targetSum, the current 
 *   path line needs to be copied to the result res. The time for a single copy is O(h),
 *   where h is the height of the tree.
 *    - For a balanced tree: O(n×logn)
 *    - For a skewed tree (height = n), each path is O(n) long:
 *     O(n×n)=O(n^2)
 * Space complexity: 
 *   The space cost depends on recursion depth:
 *    - Balanced binary tree: Height is O(log n), so space is O(log n).
 *    - Skewed tree (linked list-like): Height is O(n), so space is O(n)
**/

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> res;
    vector<int> line;
    pathSum(root, targetSum, res, line);
    return res;
}

void pathSum(TreeNode* root, int targetSum, vector<vector<int>>& res,
             vector<int>& line) {
    if (!root) {
        return;
    }

    line.push_back(root->val);
    if (root->val == targetSum && !root->left && !root->right) {
        res.push_back(line);
    }

    if (root->left) {
        pathSum(root->left, targetSum - root->val, res, line);
    }

    if (root->right) {
        pathSum(root->right, targetSum - root->val, res, line);
    }

    line.pop_back();
}

/** 
 * Solution 2: BFS -- inorder
 * 
 * Time complexity :
 *   Same as DFS solution. 
 * Space complexity:  Need more details...
 *   - Worst case (skewed tree, all paths valid): O(n^2)
 *   
**/

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> res;
    vector<TreeNode*> st;
    TreeNode *cur = root, *pre = nullptr;
    int val = 0;

    while (cur || !st.empty()) {
        while (cur) {
            st.push_back(cur);
            val += cur->val;
            cur = cur->left;
        }

        cur = st.back();
        if (val == targetSum && !cur->left && !cur->right) {
            vector<int> v;
            for (auto& tmp : st) {
                v.push_back(tmp->val);
            }
            res.push_back(v);
        }

        if (cur->right && cur->right != pre) {
            cur = cur->right;
        } else {
            pre = cur;
            val -= cur->val;
            cur = nullptr;
            st.pop_back();
        }
    }
    return res;
}

// Todo more solutions, maybe preorder and postorder int