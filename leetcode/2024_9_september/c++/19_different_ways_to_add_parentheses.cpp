// TIME COMPEXITY
// O(2^n * n)

// SPACE COMPEXITY
// O(2^n)

// CODE

class Solution {
public:
    int solve(int x, int y, char op){
        if(op == '+') return x + y;
        if(op == '-') return x - y;
        return x * y;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        bool isNum = true;
        for(int i = 0; i < expression.size(); i++){
            if(!isdigit(expression[i])){
                isNum = false;

                vector<int> left = diffWaysToCompute(expression.substr(0,i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));

                for(auto x : left){
                    for(auto y : right){
                        ans.push_back(solve(x,y,expression[i]));
                    }
                }
            }
        }

        if(isNum){
            ans.push_back(stoi(expression));
        }
        return ans;
    }
};