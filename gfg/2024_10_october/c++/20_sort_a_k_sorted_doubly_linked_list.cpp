// CODE

class Solution {
  public:
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        if(head==NULL) return head;
        priority_queue<int,vector<int>,greater<int>>pq;
        int i=0;
        while(i<k+1 && head!=NULL){
            pq.push(head->data);
            head=head->next;
            i++;
        }
        DLLNode *temp=new DLLNode(-1);
        DLLNode *prevs=new DLLNode(NULL);
        DLLNode *ans=temp;
        temp->prev=prevs;
        
        while(!pq.empty()){
            int k=pq.top();
            pq.pop();
            temp->next=new DLLNode(k);
            prevs=temp;
            temp=temp->next;
            temp->prev=prevs;
            if(head!=NULL)pq.push(head->data);
           if(head!=NULL) head=head->next;
            
        }
        
        return ans->next;
        
    }
};