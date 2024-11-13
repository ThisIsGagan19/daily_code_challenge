// CODE

class Solution {
  public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) 
    {
        if(!head1 || !head2)
            return -1;
        
        unordered_map<Node*, int> mp;
        Node* temp = head1;
        
        while(temp)
        {
            mp[temp]++;
            temp = temp->next;
        }
        
        temp = head2;
        
        while(temp)
        {
            mp[temp]++;
            
            if(mp[temp] > 1)
                return temp->data;
            temp = temp->next;
        }

        return -1;
    }
};