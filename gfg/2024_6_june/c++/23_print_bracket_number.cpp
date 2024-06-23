// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        vector<int>ans;
        int n=str.length();
        int cnt=0;
        stack<int>st;
        for(int i=0;i<n;i++){
            if(str[i]=='('){
                cnt++;
                st.push(cnt);
                ans.push_back(cnt);
            }
            else if(str[i]==')'){
                
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;
    }
};