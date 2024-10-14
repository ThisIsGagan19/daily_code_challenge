// CODE

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        while(k>0)
        {
            int x=pq.top();
            pq.pop();
            pq.push(ceil(x/3.0));
            ans+=x;
            k--;
        }
        
        return ans;
    }
};