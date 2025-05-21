// Date   : 2025-03-31

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-03-31 10:22:32
 */

ListNode *rotateRight(ListNode *head, int k) {
    if (!head) {
        return head;
    }
    int len = 1; // ingenious
    ListNode *cur = head;
    while (cur->next) {
        ++len;
        cur = cur->next;
    }
    cur->next = head; // ingenious
    int m = len - k % len;
    while (m-- > 0) {
        cur = cur->next;
    }
    ListNode *newHead = cur->next;
    cur->next = nullptr;
    return newHead;
}

// Todo more solution