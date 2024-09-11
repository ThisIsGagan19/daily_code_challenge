// TIME COMPEXITY
// O(nlogn)

// SPACE COMPEXITY
// O(n)

// CODE

class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        priority_queue<long long , vector<long long> , greater<long long > > pq;
        long long ans = 0;
        for(auto it : arr){
            pq.push(it);
        }
        
        while(pq.size() > 1){
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            
            long long sum = a + b;
            ans += sum;
            pq.push(sum);
        }
        return ans;
    }
};