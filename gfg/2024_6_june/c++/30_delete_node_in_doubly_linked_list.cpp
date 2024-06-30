// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
  public:
    
    void DeletionNode(Node* &head, Node* &tail, int position){
    // delete at first node
        if(position == 1){
            Node* temp = head;
            temp->next->prev = NULL;
            head = temp->next;
            temp->next = NULL;
            // memory free kra do
            delete temp;
        }
        else{
            // delete at any position
            Node* curr = head;
            Node* prev = NULL;
            int cnt = 1;
            while(cnt < position){
                prev = curr;
                curr = curr -> next;
                cnt++;
            }
            curr->prev = NULL;
            prev -> next = curr -> next;
            curr -> next = NULL;
            delete curr;
            tail = prev;
        }
    }
    Node* deleteNode(Node* head, int x) {
        Node * tail = head;
        DeletionNode(head,tail,x);
        return head;
        
    }
    
};