// Date   : 2025-04-16

/**
 * @Solution 1: Iterative solution
 * @Time complexity: O(m+n)
 *  m: length of list1
 *  n: length of list2
 * @Space complexity: O(1)
 * @Date: 2025-04-16 09:30:53
 */

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *dummy = new ListNode(-1), *pre = dummy;
    while (list1 && list2) {
        if (list1->val < list2->val) {
            pre->next = list1;
            list1 = list1->next;
        } else {
            pre->next = list2;
            list2 = list2->next;
        }
        pre = pre->next;
    }
    pre->next = list1 ? list1 : list2;
    return dummy->next;
}

/**
 * @Solution 2: Recursive solution
 * @Time complexity: O(m+n)
 * @Space complexity: O(m+n)
 * @Date: 2025-04-16 09:42:40
 */

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (!list1) {
        return list2;
    }
    if (!list2) {
        return list1;
    }

    if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}