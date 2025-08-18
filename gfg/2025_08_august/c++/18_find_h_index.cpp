// TC : O(N)
// SC : O(N)

// CODE

class Solution {
  public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> freq(n+1,0);
        for(int it : citations){
            if(it >= n){
                freq[n]++;
            }
            else{
                freq[it]++;
            }
        }
        
        int total = 0;
        for(int i = n; i >= 0; i--){
            total += freq[i];
            if(total >= i){
                return i;
            }
        }
        return 0;
    }
};