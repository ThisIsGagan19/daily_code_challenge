// CODE

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        // your code here
        int n=arr.size();
        if(k > n) return {};
        priority_queue<pair<int,int>>pq;
        int sum=0;
        int st=1;
        vector<int>ans;
        
        for(int i=0;i<k;i++)
        {
            pq.push({arr[i],i});
        }
        ans.push_back(pq.top().first);
        
        for(int i=k;i<n;i++)
        {
            pq.push({arr[i],i});
            while(!pq.empty() && pq.top().second < st) pq.pop();
            ans.push_back(pq.top().first);
            st++;
        }
        return ans;
    }
};