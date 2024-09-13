// TIME COMPEXITY
// O(n * m)

// SPACE COMPEXITY
// O(n)

// CODE

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto it : queries){
            int st = it[0];
            int end = it[1];
            int temp = arr[st];
            for(int i = st + 1; i <= end; i++){
                temp = temp ^ arr[i];
            }
            ans.push_back(temp);
        }

        return ans;
    }
};