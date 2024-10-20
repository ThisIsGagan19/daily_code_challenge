// CODE

class Solution {
public:
    bool parseBoolExpr(string e) {
        stack<char> s;
        for(int i = 0; i < e.size(); ++i){
            s.push(e[i]);

            if(s.top() == ')'){
                int fCount = 0;
                int tCount = 0;
                char exp = '\0';
                while(s.top() != '&' && s.top() != '|' && s.top() != '!'){
                    if(s.top() == 'f'){
                        fCount++;
                    }
                    else if(s.top() == 't'){
                        tCount++;
                    }
                    s.pop();
                }
                exp = s.top();
                s.pop();
                switch(exp){
                    case '!':
                        exp = fCount > 0? 't': 'f';
                        break;
                    case '&':
                        exp = fCount > 0? 'f': 't';
                        break;
                    case '|':
                        exp = tCount > 0? 't': 'f';
                        break;
                }
                s.push(exp);
            }
        }
        return s.top() == 't'? 1: 0;
    }
};