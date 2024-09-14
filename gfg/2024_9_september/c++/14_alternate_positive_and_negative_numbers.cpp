// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(n)

// CODE

class Solution {
  public:

    void rearrange(vector<int> &arr) {
        int n = arr.size();
        vector<int> pos;
        vector<int> neg;
        for(int i = 0; i < n; i++){
            if(arr[i] >= 0){
                pos.push_back(arr[i]);
            }
            else{
                neg.push_back(arr[i]);
            }
        }
        
        int i = 0, j = 0, k = 0;
        while(k < n){
            // ek +ve ka daalo
            // ek -ve ka daalo
            if(i < pos.size()){
                arr[k] = pos[i];
                i++;
                k++;
            }
            if(j < neg.size()){
                arr[k] = neg[j];
                j++;
                k++;
            }
        }
        
    }
};