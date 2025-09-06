// TC = O(N) + O(L) where L is length of loop = O(N)
// SC = O(1)

// CODE

class Solution {
  public:
    int findLen(Node *s, Node *f){
        int cnt = 1;
        f = f->next;
        while(s != f){
            cnt++;
            f = f->next;
        }
        return cnt;
    }
    int lengthOfLoop(Node *head) {
        Node* s = head;
        Node* f = head;
        
        while(f != NULL && f->next != NULL){
            s = s->next;
            f = f->next->next;
            if(s == f){
                return findLen(s,f);
            }
        }
        return 0;
    }
};