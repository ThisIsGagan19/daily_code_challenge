// CODE

class Solution {
    public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int n = arr.size();
        int curr = 0;
        for(int i = 0;i<n;i++)
        {
            if(arr[i] != 0)
            {
                arr[curr++] = arr[i];
            }
        }
        while(curr<n)
        {
            arr[curr++] = 0;
        }
    }
};