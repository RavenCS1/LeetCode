struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* current = head;
    current -> val = 0;
    current -> next = NULL;
    int remember = 0;
    struct ListNode* new = NULL;
    while(l1 && l2){
        if(remember + l1 -> val + l2 -> val >= 10){
            current -> val = (remember + l1 -> val + l2 -> val) % 10;
            remember = 1;
        }
        else{
            current -> val = remember + l1 -> val + l2 -> val;
            remember = 0;
        }
        if(l1 -> next == NULL && l2 -> next == NULL && remember == 0)
            goto end;
        new = malloc(sizeof(struct ListNode));
        new -> val = remember;
        new -> next = NULL;
        current -> next = new;
        current = current -> next;
        l1 = l1 -> next;
        l2 = l2 -> next;
    }
    if(l1){
        while(l1){
            if(remember + l1 -> val == 10){
                current -> val = 0;
                remember = 1;
            }
            else{
                current -> val = remember + l1 -> val;
                remember = 0;
            }
            if(l1 -> next == NULL && remember == 0){
                goto end;
            }
            new = malloc(sizeof(struct ListNode));
            new -> val = remember;
            new -> next = NULL;
            current -> next = new;
            current = current -> next;
            l1 = l1 -> next;
        }
    }
    else if(l2){
        while(l2){
            if(remember + l2 -> val == 10){
                current -> val = 0;
                remember = 1;
            }
            else{
                current -> val = remember + l2 -> val;
                remember = 0;
            }
            if(l2 -> next == NULL && remember == 0){
                goto end;
            }
            new = malloc(sizeof(struct ListNode));
            new -> val = remember;
            new -> next = NULL;
            current -> next = new;
            current = current -> next;
            l2 = l2 -> next;
        }
    }
    end:
    return head;
}
