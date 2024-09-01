// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int s1 = 0;
        int s2 = 0;
        int i = n1 - 1;
        int j = n2 - 1;
        
        while(i >= 0 && j >= 0){
            if(arr1[i] > arr2[j]){
                s1 += arr1[i];
                i--;
            }
            if(arr1[i] < arr2[j]){
                s2 += arr2[j];
                j--;
            }
            if(arr1[i] == arr2[j]){
                if(s1 > s2){
                    s1 += arr1[i];
                    s2 = s1;
                }
                else{
                    s2 += arr2[j];
                    s1 = s2;
                }
                i--;
                j--;
            }
        }
        
        while(i >= 0){
            s1 += arr1[i];
            i--;
        }
        while(j >= 0){
            s2 += arr2[j];
            j--;
        }
        
        return max(s1,s2);
    }
};