/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Helper function to reverse a linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;

    // Step 1: Find the middle using slow and fast pointers
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half
    struct ListNode* secondHalf = reverseList(slow->next);

    // Step 3: Compare the first and second halves
    struct ListNode* firstHalf = head;
    struct ListNode* tempSecond = secondHalf;
    bool palindrome = true;

    while (tempSecond != NULL) {
        if (firstHalf->val != tempSecond->val) {
            palindrome = false;
            break;
        }
        firstHalf = firstHalf->next;
        tempSecond = tempSecond->next;
    }

    // Optional: Restore the original list
    slow->next = reverseList(secondHalf);

    return palindrome;
}
