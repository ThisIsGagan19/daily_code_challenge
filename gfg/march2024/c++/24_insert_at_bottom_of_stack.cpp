// CODE

class Solution{
    public:
    void solve(stack<int> &st, int x) {
        if(st.empty()) {
            st.push(x);
            return ;
        }
        int val = st.top();
        st.pop();
        solve(st, x);
        st.push(val);
    }
    stack<int> insertAtBottom(stack<int> st, int x) {
        solve(st, x);
        return st;
    }
};