// CODE

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int ls=arr[arr.size()-1], j=arr.size()-1,k=arr.size()-1;;
        while(arr[j]>=ls)
            ls=arr[j--];
        if(j==-1){
            reverse(arr.begin(),arr.end());
            return;
        }
        while(arr[k]<=arr[j]) k--;
        swap(arr[j],arr[k]);
        reverse(arr.begin()+j+1,arr.end());
    }
};