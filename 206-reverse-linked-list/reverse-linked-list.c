struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    while (curr != NULL) {
        next = curr->next;    // Save next node
        curr->next = prev;    // Reverse current node’s pointer
        prev = curr;          // Move prev one step forward
        curr = next;          // Move curr one step forward
    }

    return prev;  // New head of reversed list
}