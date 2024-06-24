// TIME COMPLEXITY
// O(1)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        if(q > (2*n))return 0;
        if(q==1)return 0;
        if(q<=n+1)
        {
            return q-1;
        }
        else 
        {
            return (2*n+1 - q);
        }
    }
};