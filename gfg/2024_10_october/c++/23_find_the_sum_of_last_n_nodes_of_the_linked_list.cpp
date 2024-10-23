// CODE

class Solution {
  public:
    /*Structure of the node of the linled list is as

    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    */
    // your task is to complete this function
    // function should return sum of last n nodes
    int sumOfLastN_Nodes(struct Node* head, int n) {
        Node* back = head;
        Node* temp = head;
        int sum = 0;
        while(temp != NULL){
            if(n == 0){
                sum -= back->data;
                back = back->next;
            }
            sum += temp->data;
            temp = temp->next;
            
            if(n > 0) n--;
        }
        return sum;
    }
};