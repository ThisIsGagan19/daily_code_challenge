// TC = O(N)
// SC = O(1)

// CODE

class Solution {
  public:
    Node* segregate(Node* head) {
        if(head == NULL || head->next == NULL) return head;
        Node* d0 = new Node(-1);
        Node* zero = d0;
        Node* d1 = new Node(-1);
        Node* one = d1;
        Node* d2 = new Node(-1);
        Node* two = d2;
        
        Node* temp = head;
        while(temp != NULL){
            if(temp->data == 0){
                zero->next = temp;
                zero = temp;
                temp = temp->next;
            }
            else if(temp->data == 1){
                one->next = temp;
                one = temp;
                temp = temp->next;
            }
            else{
                two->next = temp;
                two = temp;
                temp = temp->next;
            }
        }
        zero->next = (d1->next) ? d1->next : d2->next;
        one->next = d2->next;
        two->next = NULL;
        return d0->next;
    }
};