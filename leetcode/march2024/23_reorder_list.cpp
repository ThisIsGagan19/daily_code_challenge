// INTUITION
// Find middle, reverse second half and merge lists :)

// CODE

class Solution {
public:
    ListNode* getMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
           slow = slow -> next;
           fast = fast -> next -> next;   
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head){ 
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(head){
           next = head -> next;
           head -> next = prev;
           prev = head;
           head = next; 
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* mid = getMiddle(head);
        ListNode* reversed = reverseList(mid -> next);
        mid -> next = NULL;
        while(head && reversed) {
           ListNode* nn = head -> next;     
           ListNode* rn = reversed -> next;
           head -> next = reversed;          
           head -> next -> next = nn;
           head = nn;
           reversed = rn;
        }
    }
};