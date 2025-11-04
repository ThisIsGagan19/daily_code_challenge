// APPROACH : we will use the concept of sliding window to maintain the K length subarray and store it in a map then traverse in the map and maintain the min heap of X size, further you know what you need to do.

// TC : (n * klogk)
// SC : O(k)

//CODE

class Solution {
public:
    int solve(unordered_map<int,int>& mp, int x){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto it : mp){
            pq.push({it.second, it.first});
            if(pq.size() > x){
                pq.pop();
            }
        }
        int sum = 0;
        while(!pq.empty()){
            int num = pq.top().second;
            int freq = pq.top().first;
            pq.pop();
            sum = sum + freq * num;
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        unordered_map<int,int> mp;
        int n = nums.size();
        int i = 0;
        int j = 0;
        while(j < n){
            mp[nums[j]]++;
            if(j-i+1 == k){
                ans.push_back(solve(mp,x));
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(mp[nums[i]]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};