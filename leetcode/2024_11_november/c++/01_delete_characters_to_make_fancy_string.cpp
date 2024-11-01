// CODE

class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size();
        string ans="";
        int count=1;
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<n;i++){
            if(st.top()==s[i]){
                st.push(s[i]);
                count++;
                if(count==3){
                    st.pop();
                    count--;
                }
            }
            else{
                st.push(s[i]);
                count=1;
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};