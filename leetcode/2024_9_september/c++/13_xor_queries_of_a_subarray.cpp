// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(n)

// CODE

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = arr.size();
        vector<int> cumm_xor(n);
        cumm_xor[0] = arr[0];
        for(int i = 1; i < n; i++){
            cumm_xor[i] = cumm_xor[i-1] ^ arr[i];
        }
        for(auto it : queries){
            int st = it[0];
            int end = it[1];

            int val = cumm_xor[end] ^ (st == 0 ? 0 : cumm_xor[st-1]);
            ans.push_back(val);
        }
        return ans;
    }
};