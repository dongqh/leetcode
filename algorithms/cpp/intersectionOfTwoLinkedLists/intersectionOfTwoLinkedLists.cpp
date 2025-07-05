// Date   : 2025-07-06

/**********************************************************************************
 * Given the heads of two singly linked-lists headA and headB, return the node
 *at which the two lists intersect. If the two linked lists have no intersection
 *at all, return null. For example, the following two linked lists begin to
 *intersect at node c1:
 *
 * The test cases are generated such that there are no cycles anywhere in the
 *entire linked structure. Note that the linked lists must retain their original
 *structure after the function returns.
 *
 * Custom Judge:
 * The inputs to the judge are given as follows (your program is not given these
 *inputs):
 *  - intersectVal - The value of the node where the intersection occurs. This
 *is 0 if there is no intersected node.
 *  - listA - The first linked list.
 *  - listB - The second linked list.
 *  - skipA - The number of nodes to skip ahead in listA (starting from the
 *head) to get to the intersected node.
 *  - skipB - The number of nodes to skip ahead in listB (starting from the
 *head) to get to the intersected node. The judge will then create the linked
 *structure based on these inputs and pass the two heads, headA and headB to
 *your program. If you correctly return the intersected node, then your solution
 *will be accepted.
 **********************************************************************************/

/**
 * @Solution 1:
 * @Time complexity: O(m + n)
 * @Space complexity: O(1)
 * @Date: 2025-07-06 15:39:48
 */

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) {
        return nullptr;
    }
    int lenA = length(headA);
    int lenB = length(headB);

    if (lenA < lenB) {
        for (int i = 0; i < lenB - lenA; ++i) {
            headB = headB->next;
        }
    } else {
        for (int i = 0; i < lenA - lenB; ++i) {
            headA = headA->next;
        }
    }

    while (headA && headB && headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }

    return (headA && headB) ? headA : nullptr;
}

int length(ListNode *head) {
    int res = 0;
    while (head) {
        ++res;
        head = head->next;
    }
    return res;
}

/**
 * @Solution 2:
 *
 * Two pointers traverse the two linked lists respectively. When they reach the
 * end, they switch to the head of the other list. In this way, they will
 * eventually meet at the intersection point (if there is one); otherwise, they
 * will reach nullptr at the same time.
 *
 * @Time complexity: O(m + n)
 *  m: the length of headA
 *  n: the length of headB
 * @Space complexity: O(1)
 * @Date: 2025-07-06 15:39:14
 */

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) {
        return nullptr;
    }
    ListNode *a = headA, *b = headB;
    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a;
}