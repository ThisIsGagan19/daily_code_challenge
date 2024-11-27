// CODE

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int output = 1;
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i] == output) output++;
        }
        return output;
    }
};