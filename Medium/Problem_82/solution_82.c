struct ListNode* deleteDuplicates(struct ListNode* head){
    if(!head) return 0;
    struct ListNode* tmp = head -> next;
    struct ListNode* tail = head;
    struct ListNode* pretail = head;
    bool flag = false, between = false, moved = false;
    while(tmp){
        if(tail -> val != tmp -> val && !flag){
            tail -> next = tmp;
            tail = tail -> next;
            if(moved) pretail = pretail -> next;            
            moved = true;
            goto end;
        }
        if(tail -> val != tmp -> val && flag && !between){
            if(head != tail) tail = tmp;
            else head = pretail = tail = tmp;
            if(moved) pretail = pretail -> next;  
            flag = false;
            goto end;
        }
        if(tail -> val != tmp -> val && flag && between){
            pretail -> next = tmp;
            tail = tmp;
            flag = false;
            goto end;
        }
        if(tail -> val == tmp -> val){
            flag = true;
            if(head != tail) between = true;
        }
        end:
            tmp = tmp -> next;
    }
    if(flag){
        if(head != tail && between)
            pretail -> next = 0;
        else if(head != tail && !between)
            head -> next = 0;
        else
            return 0;
    }
    return head;
}
