// CODE

class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
    Node* temp = head;
    int count = 0, count1 = 0;

    // Count the number of nodes in the list
    while (temp != NULL) {
        count1++;
        temp = temp->next;
    }

    // Reset temp to head
    temp = head;

    // Traverse to find the correct insertion point
    while (temp != NULL && temp->data < x) {
        temp = temp->next;
        count++;
    }

    // Insert at the beginning
    if (count == 0) {
        Node* start = new Node();
        start->data=x;start->next=NULL;start->prev=NULL;
        start->next = temp;
        if (temp != NULL) temp->prev = start;
        head = start;
    }
    // Insert at the end
    else if (count == count1) {
        Node* last = new Node();
        last->data=x;last->next=NULL;last->prev=NULL;
        temp = head;
        while (temp->next != NULL) temp = temp->next; // Find the last node
        temp->next = last;
        last->prev = temp;
    }
    // Insert in the middle
    else {
        Node* curr = new Node();
        curr->data=x;curr->next=NULL;curr->prev=NULL;
        Node* ahead = temp;
        temp = temp->prev;
        temp->next = curr;
        curr->prev = temp;
        curr->next = ahead;
        ahead->prev = curr;
    }

    return head;
}
};