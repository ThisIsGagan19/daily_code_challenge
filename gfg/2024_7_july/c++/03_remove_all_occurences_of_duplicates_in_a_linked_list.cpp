// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        Node *curr = head;
        Node * temp = new Node(-1);
        Node * new_head = temp;
        
        while(curr != NULL){
            if(curr->next == NULL){
                temp->next = curr;
                temp = temp->next;
                break;
            }
            
            // if duplicates found
            if(curr->data == curr->next->data){
                while(curr->next != NULL && curr->data == curr->next->data){
                    curr = curr->next;
                }
                curr = curr->next;
                continue;
            }
            
            temp->next = curr;
            temp = temp->next;
            curr = curr->next;
        }
        
        temp->next = NULL;
        return new_head->next;
    }
};