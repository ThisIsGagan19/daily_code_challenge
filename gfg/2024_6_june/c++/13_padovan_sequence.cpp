// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution
{
    public:
    int mod = 1e9 + 7;
    int padovanSequence(int n)
    {
       vector<int> ans(n+1);
       
       ans[0] = 1;
       ans[1] = 1;
       ans[2] = 1;
       
       for(int i = 3; i <= n; i++){
           ans[i] = (ans[i-2] % mod + ans[i-3] % mod) % mod;
       }
       
       return ans[n];
    }
    
};