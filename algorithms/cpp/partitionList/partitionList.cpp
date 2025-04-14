// Date   : 2025-04-15

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-04-15 09:22:22
 * @LastEditTime: Do not edit
 */

ListNode *partition(ListNode *head, int x) {
    ListNode *dummy = new ListNode(-1), *pre = dummy;
    dummy->next = head;
    auto cur = head; // attention
    while (pre->next && pre->next->val < x) {
        pre = pre->next;
    }
    cur = pre; // attention
    while (cur->next) {
        if (cur->next->val < x) {
            auto t = cur->next;
            cur->next = t->next;
            t->next = pre->next;
            pre->next = t;
            pre = pre->next;
        } else {
            cur = cur->next;
        }
    }
    return dummy->next;
}