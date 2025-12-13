struct ListNode* swapPairs(struct ListNode* head){
    if(head == NULL || head -> next == NULL)
        return head;
    struct ListNode* tmp1 = head;
    struct ListNode* tmp2 = head -> next;
    struct ListNode* prev = NULL;
    struct ListNode* next = head -> next -> next;
    head = tmp2;
    tmp2 -> next = tmp1;
    tmp1 -> next = next;
    prev = tmp1;
    tmp1 = next;
    if(tmp1 != NULL) tmp2 = tmp1 -> next;
    if(tmp2 != NULL) next = tmp2 -> next;
    while(tmp1 != NULL && tmp2 != NULL){
        prev -> next = tmp2;
        tmp2 -> next = tmp1;
        tmp1 -> next = next;
        prev = tmp1;
        tmp1 = next;
        if(tmp1 != NULL) tmp2 = tmp1 -> next;
        if(tmp2 != NULL) next = tmp2 -> next;
    }
    return head;
}
