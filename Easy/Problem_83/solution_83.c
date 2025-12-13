struct ListNode* deleteDuplicates(struct ListNode* head){
    if(!head) return 0;
    struct ListNode* tmp = head -> next;
    struct ListNode* tail = head;
    bool flag = false;
    while(tmp){
        if(tail -> val != tmp -> val && !flag){
            tail -> next = tmp;
            tail = tail -> next;
            goto end;
        }
        if(tail -> val != tmp -> val && flag){
            tail -> next = tmp;
            tail = tmp;
            flag = false;
            goto end;
        }
        if(tail -> val == tmp -> val) flag = true;
        end:
            tmp = tmp -> next;
    }
    if(flag) tail -> next = 0;
    return head;
}
