// TC : O(NlogN)
// SC : O(N)

// CODE

class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        int n = arr.size();
        int totalLucky = (n+1) / 2;
        int countLucky = 0;
        int ans = 0;
        vector<int> kitna;
        for(int i = 0; i < n; i++){
            if(arr[i] % k == 0){
                countLucky++;
            }
            else{
                kitna.push_back(k-(arr[i]%k)); // it gives ki kitna lagega num ko k se divide karne ke liye
            }
        }
        if(countLucky >= totalLucky) return 0;
        int need = totalLucky - countLucky;
        sort(kitna.begin(), kitna.end());
        for(int i = 0; i < need; i++){
            ans += kitna[i];
        }
        return ans;
    }
};