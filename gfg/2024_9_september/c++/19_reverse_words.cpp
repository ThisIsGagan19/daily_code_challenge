// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(n)

// CODE

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        string temp = "";
        string ans = "";
        S = S + ".";
        int cnt = 0;
        for(int i = 0; i < S.length(); i++){
            char c = S[i];
            if(c != '.'){
                temp = temp + c;
            }
            else if(cnt <= 0){
                ans = temp + ans;
                temp = "";
                cnt++;
            }
            else{
                ans = temp + "." + ans;
                temp = "";
            }
        }
        return ans;
    } 
};