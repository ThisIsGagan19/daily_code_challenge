// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        vector<int> ans;
        for(int i = 0; i < arr.size(); i++){
            int num = abs(arr[i]);
            if(arr[num - 1] < 0) ans.push_back(num);
            else arr[num - 1] *= -1;
        }
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > 0) ans.push_back(i+1);
        }
        return ans;
    }
};