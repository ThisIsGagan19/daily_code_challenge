// TC : O(N)
// SC : O(N)


// CODE

class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(char ch : s){
            if(ch >= 48 && ch <= 57){
                st.pop();
                continue;
            }
            st.push(ch);
        }
        string ans = "";
        if(st.empty()) return "";
        if(!st.empty()){
            while(!st.empty()){
                ans += st.top();
                st.pop();
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;


    }
};


//  IN-PLACE

// TC : O(N)
// SC : O(1)

class Solution {
public:
    string clearDigits(string s) {
        // This variable keeps track of the actual length of the resulting
        // string
        int answerLength = 0;

        // Iterate through each character in the input string
        for (int i = 0; i < s.size(); i++) {
            // If the current character is a digit
            if (isdigit(s[i])) {
                // Decrement answerLength to remove the last character from the
                // result
                answerLength = max(answerLength - 1, 0);
            } else {
                // Place the character in the "answer" portion of the string
                s[answerLength++] = s[i];
            }
        }

        // Resize the string to match the actual length of the answer
        s.resize(answerLength);

        return s;
    }
};