// Date   : 2025-05-22

/**
 * @Solution: Merge Sort
 * @Time complexity: O(n log(n))
 * @Space complexity: O(log(n))
 * @Date: 2025-05-22 22:39:17
 */

ListNode *sortList(ListNode *head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode *slow = head, *fast = head, *pre = head;
    while (fast && fast->next) {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = nullptr;
    return mergeSort(sortList(head), sortList(slow));
}

ListNode *mergeSort(ListNode *p, ListNode *q) {
    ListNode *dummy = new ListNode(-1);
    ListNode *pre = dummy;
    while (p && q) {
        if (p->val < q->val) {
            pre->next = p;
            p = p->next;
        } else {
            pre->next = q;
            q = q->next;
        }
        pre = pre->next;
    }
    if (p) {
        pre->next = p;
    }
    if (q) {
        pre->next = q;
    }
    return dummy->next;
}

// Todo more solution, see the tag