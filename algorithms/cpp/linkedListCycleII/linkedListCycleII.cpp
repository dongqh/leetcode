// Date   : 2025-03-22

/**
 * Solution 1: Floyd’s Cycle Detection Algorithm
 *   slow fast point solution.
 *
 * Time complexity : O(n)
 *
 * Space complexity: O(1)
 *
 **/

ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    bool flag{false};
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            flag = true;
            break;
        }
    }

    if (!flag) {
        return NULL;
    }

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

// Todo recursive Solution

ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    if (!fast || !fast->next) { // neat trick
        return nullptr;
    }

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow; // return fast is ok
}