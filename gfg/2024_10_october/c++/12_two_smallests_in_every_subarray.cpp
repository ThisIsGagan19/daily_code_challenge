// CODE

class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        int n=arr.size();
        if(n<2){
            return -1;
        }
        int sum =arr[0]+arr[1];
        int maxi=sum;
        for(int i=2;i<n;i++){
            sum+=(arr[i]-arr[i-2]);
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};