// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
  public:
    Node * reverseKaryunga(Node * head){
        Node* prev = NULL;
        Node* next = NULL;
        Node* curr = head;
        
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    Node* addOne(Node* head) {
        head = reverseKaryunga(head);
        Node* temp = head;
        Node* tail = NULL;
        int carry = 1;
        
        while(temp && carry){
            if(temp->data == 9){
                temp->data = 0;
            }
            else{
                temp->data = temp->data + 1;
                carry = 0;
            }
            tail = temp;
            temp = temp->next;
        }
        
        // last carry ko add kro new node me. case of all 999s
        if(carry){
            tail->next = new Node(1);
        }
        head = reverseKaryunga(head);
        return head;
    }
};