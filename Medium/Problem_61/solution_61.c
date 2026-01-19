struct ListNode* rotateRight(struct ListNode* head, int k){
    if(!head || head -> next == 0) {return head;}
    struct ListNode* tmp, *pretmp;
    tmp = pretmp = 0;
    bool flag = false;
    int counter = 1;
    for(tmp = head; tmp -> next != 0; tmp = tmp -> next){
        counter++;
    }
    k = k % counter;
    for(int i = k; i > 0; --i){
        for(tmp = head; tmp -> next != 0; tmp = tmp -> next){
            if(tmp -> next -> next == 0) {pretmp = tmp;}
        }
        pretmp -> next = 0;
        tmp -> next = head;
        head = tmp;
    }
    return head;
}
