// TC : O(N*Log(N) + N*Log(maxDiff))
// SC : O(1)

class Solution {
  public:
    bool ansDega(vector<int>& arr, int k, int diff){
        int cnt = 1;
        int lastChosen = arr[0];
        
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - lastChosen >= diff){
                cnt++;
                lastChosen = arr[i];
            }
            if(cnt >= k) return true;
        }
        return false;
    }
    int maxMinDiff(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int l = 0;  // difference starting point
        int r = arr[n-1] - arr[0]; // difference last point
        // l and r is the range of the difference or you can say the range if the answer
        int ans = 0;
        
        while(l <= r){
            int m = l + (r-l) / 2;
            if(ansDega(arr,k,m)){
                ans = m;
                l = m+1;
            }
            else{
                r = m-1;
            }
        }
        return ans;
        
    }
};
