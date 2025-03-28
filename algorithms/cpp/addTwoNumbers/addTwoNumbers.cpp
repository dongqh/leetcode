// Date   : 2025-03-29

/**
 * @Solution 1:
 * @Time complexity: O(max(m, n))
 * @Space complexity: O(max(m, n))
 * @Date: 2025-03-29 15:59:33
 */

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    ListNode *dummy = new ListNode(-1), *pre = dummy;

    while (l1 || l2) {
        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        sum = sum % 10;
        pre->next = new ListNode(sum);
        pre = pre->next;
    }
    if (carry == 1) {
        pre->next = new ListNode(1);
    }
    return dummy->next;
}
