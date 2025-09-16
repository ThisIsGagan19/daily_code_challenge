// TC = O(N)
// SC = O(N)

// CODE

class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        stack<int> st;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == "+"){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                
                int res = a + b;
                st.push(res);
            }
            else if(arr[i] == "-"){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int res = a - b;
                st.push(res);
            }
            else if(arr[i] == "*"){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int res = a * b;
                st.push(res);
            }
            else if(arr[i] == "/"){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int res = a / b;
                int rem = abs(a) % abs(b);
                if(rem != 0 && ((a*b) < 0)) res--;
                st.push(res);
            }
            else if(arr[i] == "^"){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int res = (int)pow(a,b);
                st.push(res);
            }
            else{
                st.push(stoi(arr[i]));
            }
        }
        return st.top();
        
    }
};