// CODE

class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
    
            // approach 1
    
            // unordered_set<int> st;
            // for(int i = nums.size() - 1; i >= 0; i--){
            //     if(st.contains(nums[i])){
            //         return i/3 + 1;
            //     }
            //     st.insert(nums[i]);
            // }
            // return 0;
    
            // approach 2
            bool arr[101] = {0};
            for(int i = nums.size() - 1; i >= 0; i--){
                if(arr[nums[i]]){
                    return i/3 + 1; 
                }
                arr[nums[i]] = true;
            }
            return 0;
        }
    };