// COPIED
// CODE

class Solution {
    public:
        #define ll long long
        long long countInterestingSubarrays(vector<int>& nums, int mod, int k) 
        {
            int n=nums.size();
            unordered_map<ll,ll>totalCount;
            ll cnt=0,res=0;
            for(int i=0;i<n;i++)
            {
                if(nums[i]%mod==k)
                   cnt++;
                ll r=cnt%mod;
                if(r==k)
                   res++;
                ll reqMod=(cnt-k+mod)%mod;
                res+=totalCount[reqMod];
                totalCount[r]++; 
            }
            return res;
        }
};