// CODE

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>result(n-k+1);
        int p=0;
        for(int i=0;i<n-k+1;i++){
            int prev=nums[i];
            bool flag=true;
            for(int j=i+1;j<i+k;j++){
                if(prev+1!=nums[j]){
                    flag=false;
                    result[p++]=-1;
                    break;
                }
                prev=nums[j];
            }
            if(flag){
                result[p++]=prev;
            }
        }
        return result;
    }
};