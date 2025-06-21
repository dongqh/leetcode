// Date   : 2025-07-05

/*********************************************************************************
 * Given the head of a singly linked list, reverse the list, and return the
 *reversed list.
 *
 * Example 1:
 *  Input: head = [1,2,3,4,5]
 *  Output: [5,4,3,2,1]
 *
 * Example 2:
 *  Input: head = [1,2]
 *  Output: [2,1]
 **********************************************************************************/

/**
 * @Solution 1: Iterative solution
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-07-05 09:42:02
 */

ListNode *reverseList(ListNode *head) {
    ListNode *newHead = nullptr;
    while (head) {
        auto t = head->next;
        head->next = newHead;
        newHead = head;
        head = t;
    }
    return newHead;
}

/**
 * @Solution 2: Recursive solution
 * @Time complexity: O(n)
 * @Space complexity: O(n)
 * Although each node is only processed once (yielding O(n) time), the recursive
 * implementation incurs O(n) space due to the call stack depth.
 * @Date: 2025-07-05 10:59:01
 */

ListNode *reverseList(ListNode *head) {
    if (!head || !head->next) {
        return head;
    }

    ListNode *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}
