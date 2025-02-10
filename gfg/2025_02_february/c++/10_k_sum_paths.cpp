// APPROACh : using recursion n map to store freq of prefix sum that have the potential to make the sum equals to k 
// if mp.find(currSum - k) != mp.end(), it means that there exists a previous prefix sum such that the difference between currSum and that prefix sum is k. This implies that a subpath sums up to k.

// TC : O(N)
// SC : O(N)

// CODE

class Solution {
  public:
    void solve(Node * root, int k, unordered_map<int,int> &mp, int & cnt, int currSum){
        if(root == NULL) return ;
        currSum += root->data;
        if(currSum == k) cnt++;
        if(mp.find(currSum - k) != mp.end()) cnt += mp[currSum - k];
        mp[currSum]++;
        
        solve(root->left,k,mp,cnt,currSum);
        solve(root->right,k,mp,cnt,currSum);
        
        mp[currSum]--;
    }
    int sumK(Node *root, int k) {
        unordered_map<int,int> mp;
        int cnt = 0;
        solve(root,k,mp,cnt,0);
        return cnt;
        
    }
};