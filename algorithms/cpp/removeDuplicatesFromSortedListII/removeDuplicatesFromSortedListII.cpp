// Date   : 2025-04-10

/**
 * @Solution 1: Iteration solution
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-04-10 16:31:14
 */

ListNode *deleteDuplicates(ListNode *head) {
    ListNode *dummy = new ListNode(-1), *pre = dummy;
    dummy->next = head;
    while (pre->next) {
        auto cur = pre->next;
        while (cur->next && cur->val == cur->next->val) {
            cur = cur->next;
        }
        if (pre->next == cur) {
            pre = pre->next;
        } else {
            pre->next = cur->next;
        }
    }
    return dummy->next;
}

// Todo more solution