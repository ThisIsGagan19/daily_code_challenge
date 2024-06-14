// TIME COMPLEXITY
// O(logn)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
  public:
    string armstrongNumber(int n){
        int num = n;
        int sum = 0;
        while(num > 0){
            int rem = num % 10;
            sum += (rem * rem * rem);
            num = num / 10;
        }
        if(sum == n){
            return "Yes";
        }
        return "No";
    }
};