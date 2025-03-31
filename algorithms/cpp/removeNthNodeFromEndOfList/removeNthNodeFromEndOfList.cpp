// Date   : 2025-04-02

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-04-02 14:44:14
 * @LastEditTime: Do not edit
 */

ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummy = new ListNode(-1), *pre = dummy;
    dummy->next = head;

    int len = 0;
    auto cur = pre->next;
    while (cur) {
        ++len;
        cur = cur->next;
    }

    int k = len - n;

    // pre->next = head;
    for (int i = 0; i < k; ++i) {
        pre = pre->next;
    }

    pre->next = pre->next->next;

    return dummy->next;
}

/**
 * @Solution 2: is better than solution 1
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-04-02 15:09:18
 * @LastEditTime: Do not edit
 */

ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummy = new ListNode(-1), *slow = dummy, *fast = dummy;
    dummy->next = head;
    while (n--) {
        fast = fast->next;
    }

    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;

    return dummy->next;
}