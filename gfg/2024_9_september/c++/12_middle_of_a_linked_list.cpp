// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node* head) {
        if(head == NULL || head->next == NULL){
            return head->data;
        }
        if(head->next->next == NULL){
            return head->next->data;
        }
        
        Node * slow = head;
        Node * fast = head->next;
        
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
            }
            slow = slow->next;
        }
        
        return slow->data;
    }
};