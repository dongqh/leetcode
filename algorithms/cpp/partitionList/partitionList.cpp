// Date   : 2025-04-15

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-04-15 09:22:22
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

/**
 * @Solution 2:
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-06-27 16:31:00
 */

ListNode *partition(ListNode *head, int x) {
    ListNode *node1 = new ListNode(-1), *node2 = new ListNode(-1);
    ListNode *p1 = node1, *p2 = node2;
    while (head) {
        if (head->val < x) {
            p1->next = head;
            p1 = p1->next;
        } else {
            p2->next = head;
            p2 = p2->next;
        }
        head = head->next;
    }
    p2->next = nullptr; // attention
    p1->next = node2->next;
    return node1->next;
}