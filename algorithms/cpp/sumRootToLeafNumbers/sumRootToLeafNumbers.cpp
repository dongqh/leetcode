// Date   : 2025-03-12

/*
 * Solution 1: Iterative Solution (BFS)
 * Time complexity : O(n)
 * Space complexity: 
 *  1) Worst case (linked-list-like tree): O(N)
 *  2) Average/Best case (balanced binary tree): O(log⁡N)
 *  where W is the maximum width of the tree.
 * 
*/

int sumNumbers(TreeNode* root) {
    int res = 0;
    stack<TreeNode*> st{{root}};

    while (!st.empty()) {
        auto t = st.top();
        st.pop();

        if (!t->left && !t->right) {
            res += t->val;
        }

        if (t->right) {
            t->right->val += t->val * 10;
            st.push(t->right);
        }
        if (t->left) {
            t->left->val += t->val * 10;
            st.push(t->left);
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

int sumNumbers(TreeNode* root) { return sumNumberDFS(root, 0); }

    int sumNumberDFS(TreeNode* root, int sum) {
        if (!root) {
            return 0; // cannot return 'sum'
        }

        sum = 10 * sum + root->val;

        if (!root->left && !root->right) {
            return sum;
        }

        return sumNumberDFS(root->left, sum) + sumNumberDFS(root->right, sum);
    }