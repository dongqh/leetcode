// Date   : 2025-03-31

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-03-31 15:09:38
 * @LastEditTime: Do not edit
 */

ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode *dummy = new ListNode(-1), *pre = dummy;
    dummy->next = head;
    for (int i = 0; i < left - 1; ++i) {
        pre = pre->next;
    }
    ListNode *cur = pre->next;
    for (int i = left; i < right; ++i) {
        auto tmp = cur->next;
        cur->next = tmp->next;
        tmp->next = pre->next; // attention
        pre->next = tmp;       // attention
    }
    return dummy->next;
}
