struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(n == 1 && head -> next == NULL)
        return NULL;
    struct ListNode* tmp = head;
    struct ListNode* delay = NULL;
    struct ListNode* prev = NULL;
    int counter = 0;
    bool flag = false;
    while(tmp){
        tmp = tmp -> next;
        counter++;
        if(counter == n && flag == false){
            flag = true;
            delay = head;
        }
        else if(delay == head){
            delay = delay -> next;
            prev = head;
        }
        else if(delay != head && delay != NULL){
            delay = delay -> next;
            prev = prev -> next;
        }
    }
    if(prev != NULL)
        prev -> next = delay -> next;
    else
        return delay -> next;
    return head;
}
