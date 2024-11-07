// CODE

class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        
        int totalSum = 0; 
        // total sum of all elements of array
        for(auto i : arr) {
            totalSum += i;
        }
        
        // if totalSum is not EVENLY divisible by 3
        // then it CANNOT BE split into three equal parts
        if(totalSum % 3 != 0) { 
            return {-1 , -1};
        }
        
        int part = totalSum / 3; // sum of each consecutive part 
        int i = 0 , j = arr.size() - 1; // two pointers
        int sum1 = 0 , sum2 = 0; 
        // sum1 : sum of the part from the beginning
        // sum2 : sum of the part from the end
        
        // add in sum1 until sum1 < part
        // move 'i' pointer ahead
        while( i < j && sum1 < part){ 
            sum1 += arr[i++];
        }
        
        // if sum1 != 'part'
        // it cannot be achieved
        if(sum1 != part) {
            return {-1 , -1};
        }
        
        
        // add in sum2 until sum2 < part
        // move 'j' pointer back
        while(j > i && sum2 < part){ 
            sum2 += arr[j--];
        }
        
        // if sum2 != 'part'
        // it cannot be achieved
        if(sum2 != part) {
            return {-1 , -1};
        }
        
        // sum of subarray from [0,i] = [i+1,j] = [j+1 , end]
        return {i - 1, j};
    }
};