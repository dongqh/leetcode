// Date   : 2025-07-07

/*********************************************************************************
 * Given the head of a singly linked list, group all the nodes with odd indices
 *together followed by the nodes with even indices, and return the reordered
 *list.
 *The first node is considered odd, and the second node is even, and so
 *on.
 * Note that the relative order inside both the even and odd groups should
 * remain as it was in the input.
 *
 * You must solve the problem in O(1) extra space
 *complexity and O(n) time complexity.
 *
 * Example 1:
 *  Input: head = [1,2,3,4,5]
 *  Output: [1,3,5,2,4]
 *
 * Example 2:
 *  Input: head = [2,1,3,5,6,4,7]
 *  Output: [2,3,6,7,1,5,4]
 **********************************************************************************/

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-07-07 17:05:09
 */

ListNode *oddEvenList(ListNode *head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode *pre = head, *cur = head->next;
    while (cur && cur->next) {
        ListNode *t = pre->next;
        pre->next = cur->next;
        cur->next = cur->next->next;
        pre->next->next = t; // attention

        pre = pre->next;
        cur = cur->next;
    }
    return head;
}
