// TC = O(NlogN)
// SC = O(1)

// CODE

class Solution {
  public:
    Node* findMiddle(Node* head){
        Node* s = head;
        Node* f = head->next; // vase toh dono he head se start hote h but for even length ek step aage se start krte h thaki ek step peeche ruk shke
        
        while(f && f->next){
            s = s->next;
            f = f->next->next;
        }
        return s;
    }
    Node* merge(Node* l1, Node* l2){
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        while(l1 && l2){
            if(l1->data < l2->data){
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            }
            else{
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }
        }
        if(l1) temp->next = l1;
        else temp->next = l2;
        
        return dummy->next;
    }

    Node* mergeSort(Node* head) {
        if(head == NULL || head->next == NULL) return head;
        
        Node* mid = findMiddle(head);
        Node* left = head;
        Node* right = mid->next;
        // middle node ka next pe toh null point karna hota h
        mid->next = NULL;
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        return merge(left,right);
        
    }
};