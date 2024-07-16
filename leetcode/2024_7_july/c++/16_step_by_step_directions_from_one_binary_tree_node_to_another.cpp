// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution {
public:
    bool solve(TreeNode* root, int tar, string &path){
        if(root == NULL) return false;

        if(root->val == tar) return true;

        path.push_back('L');
        if(solve(root->left, tar, path)) return true;
        path.pop_back();

        path.push_back('R');
        if(solve(root->right, tar, path)) return true;
        path.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string RTL = "";
        string RTR = "";
        string res = "";

        solve(root,startValue,RTL);
        solve(root,destValue,RTR);

        int i = 0;
        while(i < RTL.length() && i < RTR.length() && RTL[i] == RTR[i]){
            i++;
        }

        for(int j = 0; j < RTL.length() - i; j++){
            res.push_back('U');
        }

        for(int j = i; j < RTR.length(); j++){
            res.push_back(RTR[j]);
        }
        return res;
    }
};