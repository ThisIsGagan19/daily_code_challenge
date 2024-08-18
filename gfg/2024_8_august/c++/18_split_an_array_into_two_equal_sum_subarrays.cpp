// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        int totalSum = 0;
        for(int i = 0; i < arr.size(); i++){
            totalSum += arr[i];
        }
        
        int sum = 0;
        for(int i= 0; i < arr.size(); i++){
            sum += arr[i];
            if(sum * 2 == totalSum) return true;
        }
        return false;
    }
};