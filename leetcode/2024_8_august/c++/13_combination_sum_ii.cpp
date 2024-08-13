// TIME COMPEXITY
// O(2^n)

// SPACE COMPEXITY
// O(n)

// CODE

class Solution {
public:
    void solve(int ind, vector<int>& arr, int target, vector<vector<int> > &ans, vector<int> &temp){
        if(target == 0){
            ans.push_back(temp);
            return ;
        }

        for(int i = ind; i < arr.size(); i++){
            if(i > ind && arr[i] == arr[i-1]) continue;
            if(arr[i] > target) break;
            temp.push_back(arr[i]);
            solve(i+1,arr,target-arr[i],ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ans;
        vector<int> temp;
        solve(0,candidates,target,ans,temp);
        return ans;

    }
};