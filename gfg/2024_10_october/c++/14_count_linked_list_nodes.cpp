// CODE

class Solution {
  public:
    int getCount(struct Node* head) {
        int ans = 0;
        Node *curr = head;
        while(curr)
        {
            ans++;
            curr = curr->next;
        }
        return ans;
    }
};