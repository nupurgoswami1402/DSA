struct ListNode* removeElements(struct ListNode* head, int val) {
    // Dummy node to simplify head removal
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* current = &dummy;

    while (current->next != NULL) {
        if (current->next->val == val) {
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp); // free memory
        } else {
            current = current->next;
        }
    }

    return dummy.next;
}
