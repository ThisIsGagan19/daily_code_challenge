// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dum1= new ListNode(10);
        ListNode* temp=head;
        ListNode* uupp=dum1;
        while(temp->next!=NULL){
            if(temp->val==0){
              temp=temp->next;
              continue;
            } 
            int sum=0;
            while(temp->val!=0){
                sum+=temp->val;
                temp=temp->next;
            }
            uupp->next=new ListNode(sum);
            uupp=uupp->next;
        }
 return dum1->next;
    }
};