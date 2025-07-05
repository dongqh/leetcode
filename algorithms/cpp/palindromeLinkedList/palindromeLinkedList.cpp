// Date   : 2025-07-06

/*********************************************************************************
 * Given the head of a singly linked list, return true if it is a or false
 *otherwise.
 *
 * Example 1:
 *  Input: head = [1,2,2,1]
 *  Output: true
 *
 * Example 2:
 *  Input: head = [1,2]
 *  Output: false
 *
 * Follow up: Could you do it in O(n) time and O(1) space?
 **********************************************************************************/

/**
 * @Solution 1:
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-07-06 17:03:14
 */

bool isPalindrome(ListNode *head) {
    if (!head || !head->next) {
        return true;
    }

    ListNode *slow = head, *fast = head;
    // attention
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *last = slow->next, *pre = head;
    // attention
    while (last->next) {
        auto t = last->next;
        last->next = t->next;
        t->next = slow->next;
        slow->next = t;
    }
    // attention
    while (slow->next) {
        slow = slow->next;
        if (pre->val != slow->val) {
            return false;
        }
        pre = pre->next;
    }
    return true;
}

/**
 * @Solution 2:
 * @Time complexity: O(n)
 * @Space complexity: O(n)
 * @Date: 2025-07-06 17:14:43
 */

bool isPalindrome(ListNode *head) {
    if (!head || !head->next) {
        return true;
    }
    auto cur = head;
    stack<ListNode *> st;
    while (cur) {
        st.push(cur);
        cur = cur->next;
    }

    while (head) {
        auto t = st.top();
        st.pop();
        if (head->val != t->val) {
            return false;
        }
        head = head->next;
    }
    return true;
}

// Todo more solutions