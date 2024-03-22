// INTUITION
// Recursion mirrors the bouncing of a ball, it returns after hitting the base case. 
// Utilizing this, we can track forward movement with a start pointer and, upon return, 
// compare values using start and end pointers. If they remain the same throughout traversal, 
// it signifies a palindrome.

// NOTE - Although the code isn't optimized and we could improve the time complexity by 
// tracking the middle of the linked list, but here I want to show how to use the 
// bouncing nature of recursion.

// CODE

class Solution {
public:
    bool solve(ListNode *(&start), ListNode *end) {
        if(end == NULL) return 1;
        bool res = solve(start, end -> next) & (start -> val == end -> val);
        start = start -> next;
        return res;
    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head -> next) return 1;
        ListNode *start = head;
        return solve(start, head);
    }
};