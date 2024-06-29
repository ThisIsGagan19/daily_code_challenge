// TIME COMPLEXITY
// O(length of linked list)

// SPACE COMPLEXITY
// O(1)

// CODE

bool areIdentical(struct Node *head1, struct Node *head2) {
    while(head1 != NULL && head2 != NULL){
        if(head1->data != head2->data) return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    
    if(head1 != NULL || head2 != NULL) return false;
    
    return true;
}