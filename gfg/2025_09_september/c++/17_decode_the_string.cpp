// TC = O(N)
// SC = O(N)

// CODE

class Solution {
  public:
    string decodedString(string &s) {
        stack<char> st;
        string ans = "";
        for(auto ch : s){
            if(ch != ']') st.push(ch);
            if(ch == ']'){
                string temp = "";
                string temp2 = "";
                string times = "";
                while(!st.empty() && st.top() != '['){
                    char c = st.top();
                    st.pop();
                    temp += c;
                }
                reverse(temp.begin(), temp.end());
                st.pop();
                while(!st.empty() && isdigit(st.top())){
                    times += st.top();
                    st.pop();
                }
                reverse(times.begin(), times.end());
                int num = stoi(times);
                while(num--){
                    temp2 += temp;
                }
                for(int i = 0; i < temp2.size(); i++){
                    st.push(temp2[i]);
                }
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};