/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;

    // Step 1: Find middle (slow-fast pointer)
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    struct ListNode *prev = NULL, *curr = slow, *nextNode = NULL;
    while (curr) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    // Step 3: Compare first half and reversed second half
    struct ListNode *first = head;
    struct ListNode *second = prev;

    while (second) {
        if (first->val != second->val)
            return false;
        first = first->next;
        second = second->next;
    }

    return true;
}