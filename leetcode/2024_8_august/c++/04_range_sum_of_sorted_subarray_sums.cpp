// TIME COMPEXITY
// O(nlogn)

// SPACE COMPEXITY
// O(n)

// CODE

class Solution {
public:
    int mod = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > > pq;
        int ans = 0;
        for(int i = 0; i < n; i++){
            pq.push({nums[i],i});
        }
        for(int i = 1; i <= right; i++){
            int value = pq.top().first;
            int index = pq.top().second;

            pq.pop();

            if(i >= left){
                ans = (ans + value) % mod;
            }
            if(index + 1 < n){
                pq.push({value + nums[index+1], index + 1});
            }
        }
        return ans;
        
    }
};