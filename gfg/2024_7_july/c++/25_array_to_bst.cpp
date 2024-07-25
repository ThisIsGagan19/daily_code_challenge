// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution {
  public:
    Node* solve(vector<int>& nums, int l, int r){
        if(l > r) return NULL;
        if(l == r){
            return new Node(nums[l]);
        }
        
        int mid = l + (r-l)/2;
        Node* root = new Node(nums[mid]);
        root->left = solve(nums,l,mid-1);
        root->right = solve(nums,mid+1,r);
        
        return root;
    }
    Node* sortedArrayToBST(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};