// TIME COMPEXITY
// O(n+m)

// SPACE COMPEXITY
// O(n+m)

// CODE

class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int i = 0;
        int j = 0;
        vector<int> sorted;
        while(i < arr1.size() && j < arr2.size()){
            if(arr1[i] <= arr2[j]){
                sorted.push_back(arr1[i]);
                i++;
            }
            else{
                sorted.push_back(arr2[j]);
                j++;
            }
        }
        while(i < arr1.size()){
            sorted.push_back(arr1[i]);
                i++;
        }
        while(j < arr2.size()){
            sorted.push_back(arr2[j]);
                j++;
        }
        
        return sorted[k-1];
    }
};