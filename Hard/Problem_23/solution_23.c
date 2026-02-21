struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct ListNode* head = 0;
    struct ListNode* tail = 0;
    bool check, empty, first;
    check =  false;
    int smallest, choosen;
    while(!check){
        empty = first = true;
        for(register int i = 0; i < listsSize; ++i){
            if(lists[i] != 0){
                empty = false;
                if(first){
                    smallest = lists[i] -> val;
                    choosen = i;
                    first = false;
                }
                else{
                    if(lists[i] -> val < smallest){
                        smallest = lists[i] -> val;
                        choosen = i;
                    }
                }
            }
        }
        if(empty) check = true;
        else{
            if(!head){
                head = lists[choosen];
                lists[choosen] = lists[choosen] -> next;
                head -> next = 0;
                tail = head;
            }
            else{
                tail -> next = lists[choosen];
                lists[choosen] = lists[choosen] -> next;
                tail = tail -> next;
            }
        }
    }
    return head;
}
