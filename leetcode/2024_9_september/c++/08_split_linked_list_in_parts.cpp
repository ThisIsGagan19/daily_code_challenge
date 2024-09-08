// TIME COMPEXITY
// O(k + len)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int len = 0;
        while(curr != NULL){
            len++;
            curr = curr->next;
        }
        
        int ebn = len / k;
        int rn = len % k;

        vector<ListNode*> ans(k,NULL);

        curr = head;
        ListNode* prev = NULL;

        for(int i = 0; i < k; i++){
            ans[i] = curr;
            for(int cnt = 1; cnt <= ebn + (rn > 0 ? 1 : 0); cnt++){
                if(curr != NULL){
                    prev = curr;
                    curr = curr->next;
                }
            }
            if(prev != NULL) prev->next = NULL;
            rn--;
        }
        return ans;
    }
};