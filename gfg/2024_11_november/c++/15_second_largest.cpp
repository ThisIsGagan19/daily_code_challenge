// CODE

class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        int n=arr.size();
        int maxi=-1,sec_max=-1;
         for(int i=0;i<n;i++){
            if(maxi<arr[i]){
                sec_max=maxi;
                maxi=arr[i];
             }
             else if(sec_max<arr[i] && arr[i]!=maxi) sec_max=arr[i];
         }
        return sec_max;
    }
};