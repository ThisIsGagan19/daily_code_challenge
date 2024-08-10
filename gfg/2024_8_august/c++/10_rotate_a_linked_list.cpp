// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
  public:
    // Function to rotate a linked list.
    Node* rotate(Node* head, int k) {
        Node* first = head;
        Node* prev = NULL;
        Node* second = head;
        
        while(k--){
            prev = first;
            first = first->next;
        }
        // first kth ke just agli ko pointkr rha hoga
        // prev to last node bane wali h
        if(first == NULL) return head;
        
        // second node ko first pe point krake last node thke le jao
        second = first;
        while(second->next != NULL){
            second = second->next;
        }
        
        // second ko starting head pe point kra do
        second->next = head;
        
        // prev wali ko NULL pe point kra do
        prev->next = NULL;
        
        return first;
    }
};