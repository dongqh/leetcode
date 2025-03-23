// Date   : 2025-03-26

/**
 * @Solution 1: iterative solution
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-03-26 14:53:05
 */

ListNode* removeElements(ListNode* head, int val) {
    ListNode *dummy = new ListNode(-1), *pre = dummy;
    dummy->next = head;
    while (pre->next) {
        if (pre->next->val == val) {
            pre->next = pre->next->next;
        } else {
            pre = pre->next;
        }
    }
    return dummy->next;
}

/**
 * @Solution 2: recursive solution
 * @Time complexity: O(n)
 * @Space complexity: O(n)
 *  The space complexity mainly comes from the stack frames of the recursive calls. 
 *  Each recursive step goes one node deeper into the linked list, 
 *  so in the worst case (when no nodes need to be deleted or all nodes need to be deleted),
 *  the recursion depth can reach n levels.
 * @Date: 2025-03-26 14:46:43
 */

ListNode* removeElements(ListNode* head, int val) {
    if (!head) {
        return head;
    }
    if (head->val != val) {
        head->next = removeElements(head->next, val);
    } else {
        return removeElements(head->next, val);
    }
    return head;
}

/**
 * @Solution 3: recursive solution 2 
 * @Time complexity: O(n)
 * @Space complexity: O(n)
 * @Date: 2025-03-26 14:52:17
 * @LastEditTime: Do not edit
 */

 ListNode* removeElements(ListNode* head, int val) {
    if (!head) {
        return head;
    }
    head->next = removeElements(head->next, val);
    return head->val == val ? head->next : head;
}

