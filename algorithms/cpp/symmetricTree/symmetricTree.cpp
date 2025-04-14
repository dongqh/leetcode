// Date   : 2025-04-11

/**
 * @Solution 1: Recursive solution
 * @Time complexity: O(n)
 * @Space complexity:
 *  1) Worst case (linked-list-like tree): O(N)
 *  2) Average/Best case (balanced binary tree): O(log⁡N)
 * @Date: 2025-04-11 16:09:26
 */

bool isSymmetric(TreeNode *root) {
    if (!root) {
        return true;
    }
    return isSymmetric(root->left, root->right);
}

bool isSymmetric(TreeNode *p, TreeNode *q) {
    if (!p && !q) {
        return true;
    }

    if (!p && q || p && !q || p->val != q->val) {
        return false;
    }

    return isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
}

/**
 * @Solution 2: Iterative solution
 * @Time complexity: O(n)
 * @Space complexity: O(n)
 * @Date: 2025-04-14 13:10:01
 * @LastEditTime: Do not edit
 */

bool isSymmetric(TreeNode *root) {
    if (!root) {
        return true;
    }
    queue<TreeNode *> q1, q2;
    q1.push(root->left);
    q2.push(root->right);
    while (!q1.empty() && !q2.empty()) {
        auto node1 = q1.front();
        q1.pop();
        auto node2 = q2.front();
        q2.pop();
        if (!node1 && !node2) {
            continue;
        }
        if (!node1 && node2 || node1 && !node2 || node1->val != node2->val) {
            return false;
        }

        q1.push(node1->left);
        q1.push(node1->right);
        q2.push(node2->right);
        q2.push(node2->left);
    }
    return true;
}