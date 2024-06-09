// NOTE
// We don't need to sort the array, this problem can be solved in O(n).
// We just need to make sure that at an even position value is smaller than its 
// right and at an odd position value is greater than its right.

// TIME COMPLEXITY
// O(logn)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
    
  public:
    void zigZag(int n, vector<int> &arr) {
        for(int i = 0; i < arr.size() - 1; i++){
            // even and ith > (i +1)th  
            if(i % 2 == 0 && arr[i] > arr[i+1]){
                swap(arr[i],arr[i+1]);
            }
            // odd and ith < (i +1)th  
            if(i % 2 != 0 && arr[i] < arr[i+1]){
                swap(arr[i],arr[i+1]);
            }
        }
    }
};