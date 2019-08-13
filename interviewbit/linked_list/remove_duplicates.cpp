//to remove duplicates from sorted LL.
 ListNode *current = A;
  ListNode *after;
  
  while(current->next != NULL)
    {
        if(current->val == current->next->val)
          {
              after = current->next->next;
              free(current->next);
              current->next = after;
          }
          else
            current = current->next;
    }
    return A;
//two pointers current and after.


 //to remove all duplicates from LL.
 //1-1-2-3 to 2-3

 //here take a dummy node.
   if(!A || !A->next)
        return A;
        
    ListNode* fakeHead = new ListNode(0);
    fakeHead->next = A;
    ListNode* prev = fakeHead;
    while (A)
    {
        while (A->next && A->val == A->next->val)
            A = A->next;
        
        if (prev->next == A)
            prev = prev->next; 
        else 
            prev->next = A->next;
            
        A = A->next;
    }
return fakeHead->next;