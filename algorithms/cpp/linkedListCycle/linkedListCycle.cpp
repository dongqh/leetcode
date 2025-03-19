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

bool hasCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

// Todo recursive Solution