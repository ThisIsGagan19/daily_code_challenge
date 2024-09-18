// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(n)

// CODE

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> st;
        for(int i = 0; i < x.length(); i++){
            if(x[i] == '[' || x[i] == '(' || x[i] == '{') st.push(x[i]);
            else{
                if(st.empty()) return false;
                if(x[i] == ']' && st.top() == '[') st.pop();
                else if(x[i] == ')' && st.top() == '(') st.pop();
                else if(x[i] == '}' && st.top() == '{') st.pop();
                else return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }

};