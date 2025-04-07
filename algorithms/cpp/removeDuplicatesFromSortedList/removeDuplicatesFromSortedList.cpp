// Date   : 2025-04-11

/**
 * @Solution 1: iterative solution
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-04-11 12:50:01
 * @LastEditTime: Do not edit
 */

ListNode *deleteDuplicates(ListNode *head) {
    ListNode *cur = head;
    while (cur && cur->next) {
        if (cur->val == cur->next->val) {
            cur->next = cur->next->next;
        } else {
            cur = cur->next;
        }
    }
    return head;
}

/**
 * @Solution 2: Recursive solution
 * @Time complexity: O(n)
 * @Space complexity: O(n)
 * @Date: 2025-04-11 14:35:38
 * @LastEditTime: Do not edit
 */

ListNode *deleteDuplicates(ListNode *head) {
    if (!head || !head->next) {
        return head;
    }
    head->next = deleteDuplicates(head->next);
    return (head->val == head->next->val) ? head->next : head;
}