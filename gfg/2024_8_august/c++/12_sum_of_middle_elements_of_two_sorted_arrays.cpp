// TIME COMPEXITY
// O(logn)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size();
        int st = 0;
        int end = n;
        
        while(st <= end){
            int m1 = (st+end) >> 1;
            int m2 = n - m1;
            
            int l1 = (m1==0) ? INT_MIN : arr1[m1-1];
            int l2 = (m2==0) ? INT_MIN : arr2[m2-1];
            int r1 = (m1 == n) ? INT_MAX : arr1[m1];
            int r2 = (m2 == n) ? INT_MAX : arr2[m2];
            
            if(l1 <= r2 && l2 <= r1) return max(l1,l2) + min(r1,r2);
            
            if(l1 > r2) end = m1 - 1;
            else st = m1+1;
        }
        
        return -1;
    }
};