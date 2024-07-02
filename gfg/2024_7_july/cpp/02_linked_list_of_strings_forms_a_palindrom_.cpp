// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution {
  public:
    bool compute(Node* head) {
        string LL = "";
        Node * temp = head;

        while(temp != NULL){
            LL += temp->data;
            temp = temp->next;
        }
        
        string copy_of_LL = LL;
        reverse(LL.begin(), LL.end());
        
        if(LL == copy_of_LL) return true;
        
        return false;
    }
};