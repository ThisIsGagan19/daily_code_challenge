// CODE

#include<vector>
class Solution{
    private:
        /*
        bool checkPalindrome(vector<int> &arr){
            int s = 0;
            int e = arr.size()-1;
            while(s<=e){
                if(arr[s] != arr[e]){
                    return false;
                }
                else{
                    s++;
                    e--;
                }
            }
            return true;
        }
        */
        Node* getMid(Node* head){
            Node* fast = head->next;
            Node* slow = head;
            
            while(fast != NULL && fast->next != NULL){
                fast = fast->next->next;
                slow = slow->next;
            }
            return slow;
        }
        
        Node* reverse(Node* head){
            Node* curr = head;
            Node* prev = NULL;
            Node* next = NULL;
            
            while(curr != NULL){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        // approach 1
        /*
        vector<int> arr;
        Node* temp = head;
        while(temp != NULL){
            arr.push_back(temp->data);
            temp = temp->next;
        }
        return checkPalindrome(arr);
        */
        
        // approach 2
        if(head->next == NULL){
            return true;
        }
        
        // step 1 finding middle
        Node* middle = getMid(head);
        
        // step 2 reverse the LL from middle
        Node* temp = middle->next;
        middle->next = reverse(temp);
        
        Node* head1 = head;
        Node* head2 = middle->next;
        // step 3 comparing the both halves
        while(head2 != NULL){
            if(head1->data != head2->data){
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        // step4 again reverse the LL
        temp = middle->next;
        middle->next = reverse(temp);
        
        return true;
        
        
        
    }
};