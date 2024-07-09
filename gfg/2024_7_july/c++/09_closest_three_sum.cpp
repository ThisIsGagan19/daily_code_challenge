// TIME COMPLEXITY
// O(n^2)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        int diff = INT_MAX;
        int ans = INT_MAX;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++){
            int s = i+1;
            int e = arr.size()-1;
            
            while(s < e){
                int sum = arr[i] + arr[s] + arr[e];
                if(sum == target) return sum;
                else if(sum > target) e--;
                else s++;
                
                // abs difference
                if(abs(sum - target) < diff){
                    diff = abs(sum - target);
                    ans = sum;
                }
                
                // do same abs diff aa jate h toh return maximum
                else if(abs(sum-target) == diff){
                    ans = max(ans,sum);
                }
            }
        }
        return ans;
    }
};