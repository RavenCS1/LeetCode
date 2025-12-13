struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* head = NULL;
    struct ListNode* tmp = NULL;
    bool flag = false;
    while(list1 != NULL && list2 != NULL){
        if(tmp && flag == true)
            tmp = tmp -> next;
        if(list1 -> val < list2 -> val){
            if(!head)
                head = list1;
            else if(flag == false){
                head -> next = list1;
                tmp = head;
                flag = true;
            }
            else
                tmp -> next = list1;
            list1 = list1 -> next;
        }
        else{
            if(!head)
                head = list2;
            else if(flag == false){
                head -> next = list2;
                tmp = head;
                flag = true;
            }
            else
                tmp -> next = list2;
            list2 = list2 -> next;
        }
    }
    if(list1){
        if(head != NULL && tmp == NULL)
            head -> next = list1;
        else if(tmp != NULL){
            tmp = tmp -> next;
            tmp -> next = list1;
        }
        else
            head = list1;
    }
    else if(list2){
        if(head != NULL && tmp == NULL)
            head -> next = list2;
        else if(tmp != NULL){
            tmp = tmp -> next;
            tmp -> next = list2;
        }
        else
            head = list2;
    }
    return head;
}

