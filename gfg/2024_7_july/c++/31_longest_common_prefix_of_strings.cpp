// TIME COMPLEXITY
// O(n * minLen of string)

// SPACE COMPLEXITY
// O(maxLen of string)

// CODE

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        if(arr.size() == 1) return arr[0];
        
        string ans = "";
        string s1 = arr[0];
        for(int i = 1; i < arr.size(); i++){
            string temp = "";
            string s2 = arr[i];
            int j = 0;
            while(j < s1.size() && j < s2.size()){
                if(s1[j] == s2[j]){
                    temp += s1[j];
                    j++;
                }
                else break;
            }
            
            ans = temp;
            s1 = ans;
        }
        if(ans.size() == 0) return "-1";
        return ans;
    }
};