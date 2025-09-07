// TC = O(NlogK) where K is number of linked lists
// SC = O(N) for recursion stack space

// CODE

class Solution {
  public:
    Node* merge(Node* l1, Node* l2){
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        if(l1->data < l2->data){
            l1->next = merge(l1->next,l2);
            return l1;
        }
        else{
            l2->next = merge(l1,l2->next);
            return l2;
        }
        return NULL;
    }
    Node* mergeSort(int st, int end, vector<Node*>& arr){
        if(st > end) return NULL;
        if(st == end) return arr[st];
        
        int mid = st + (end - st) / 2;
        
        Node* l1 = mergeSort(st,mid,arr);
        Node* l2 = mergeSort(mid+1,end,arr);
        
        return merge(l1,l2);
    }
    Node* mergeKLists(vector<Node*>& arr) {
        return mergeSort(0,arr.size() - 1,arr);
        
    }
};