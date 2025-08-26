// TC : O(N)
// SC : O(1)

// CODE

class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        int n = s1.length();
        int m = s2.length();
        int i = 0;
        int j = 0;
        while(i < n && j < m){
            if(s1[i] == s2[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if(i >= n){
            return true;
        }
        return false;
        
    }
};