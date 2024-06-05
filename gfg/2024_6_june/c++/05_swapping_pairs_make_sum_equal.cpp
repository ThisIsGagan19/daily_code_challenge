// APPROACH
// 1 calculate sum of each both array
// 2 if rem of sum diff is not equal to 0 then simply return -1
// 3 make two pointer i and j with value 0
// 4 sort both the arrays 
// 5 make target = diff_sum / 2 
// 6 rum while loop till size of both array with i and j pointer
// 7 if diff = (a[i] - b[j]) is equal to target return 1
// 8 diff < target i++
// 9 diff > target j++
// 10 return -1 out from loop 


// TIME COMPLEXITY
// O(N + M)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        
        int sum_a = 0;
        int sum_b = 0;
        
        for(int i = 0; i < n; i++) sum_a += a[i];
        for(int i = 0; i < m; i++) sum_b += b[i];
        
        int diff_sum = sum_a - sum_b;
        
        if(diff_sum % 2 != 0) return -1;
        
        int target = diff_sum / 2;
        
        int i = 0;
        int j = 0;
        
        sort(a, a+n);
        sort(b, b+m);
        
        while(i < n && j < m){
            int diff = a[i] - b[j];
            if(diff == target) return 1;
            else if(diff < target) i++;
            else j++;
        }
        return -1;
        
    }
};