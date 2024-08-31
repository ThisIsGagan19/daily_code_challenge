// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(n)

// CODE

class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n = arr.size();
        vector<int> chota(n,INT_MAX);
        vector<int> bada(n,INT_MAX);
        chota[0] = arr[0];
        for(int i = 1; i < n; i++){
            chota[i] = min(arr[i], chota[i-1]);
        }
        bada[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; i--){
            bada[i] = max(arr[i], bada[i+1]);
        }
        for(int i = 0; i < n; i++){
            if(chota[i] < arr[i] && arr[i] < bada[i]){
                return {chota[i],arr[i],bada[i]};
            }
        }
        return {};
    }
};