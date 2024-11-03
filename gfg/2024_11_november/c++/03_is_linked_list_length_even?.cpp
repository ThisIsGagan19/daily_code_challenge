// CODE

class Solution {
  public:
    bool isLengthEven(struct Node **head) {
        // Code here
        Node*curr = *head;
        int len = 0;
        while(curr){
            len++;
            curr = curr->next;
        }
        return !(len & 1);
    }
};