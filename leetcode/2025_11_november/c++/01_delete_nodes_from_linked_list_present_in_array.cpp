// APPROACH: Using hashset
// Why we using hashset because hashset help in fast lookup, efficient deletion and no duplicates, so that we can easily know in O(1) time if an element is present or not and then easily delete them
// deleting procedure is simple we have previous and current pointer if we have to delete note then previous next equal to current next and if we don't have to delete then just make previous equal to current and in the last move current pointer forward

// TC : O(m + n) m - size of linked list, n - size of array
// SC : O(n) n - size of hashset

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for(int it : nums){
            s.insert(it);
        }
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr != NULL){
            if(s.count(curr->val)){
                prev->next = curr->next;
            }
            else{
                prev = curr;
            }
            curr = curr->next;
        }

        return dummy -> next;
    }
};