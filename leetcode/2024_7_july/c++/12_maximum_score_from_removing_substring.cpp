// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int flag = 0;
        if(x > y) flag = 1;
        int res = 0;

        stack<char> st1;
        stack<char> st2;

        for(auto c : s){
            if(!st1.empty()){
                if(flag == 1){
                    if(st1.top() == 'a' && c == 'b'){
                        res += x;
                        st1.pop();
                    }
                    else{
                        st1.push(c);
                    }
                }
                else{
                    if(st1.top() == 'b' && c == 'a'){
                        res += y;
                        st1.pop();
                    }
                    else{
                        st1.push(c);
                    }
                }
            }
            else{
                st1.push(c);
            }
        }

        string remaining;
        while (!st1.empty()) {
            remaining += st1.top();
            st1.pop();
        }
        reverse(remaining.begin(), remaining.end());

        for(auto c : remaining){
            if(!st2.empty()){
                if(!flag){
                    if(st2.top() == 'a' && c == 'b'){
                        res += x;
                        st2.pop();
                    }
                    else{
                        st2.push(c);
                    }
                }
                else{
                    if(st2.top() == 'b' && c == 'a'){
                        res += y;
                        st2.pop();
                    }
                    else{
                        st2.push(c);
                    }
                }
            }
            else{
                st2.push(c);
            }
        }

        return res;


    }
};