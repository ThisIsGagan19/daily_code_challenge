// INTUITION
// Level order traversal variation

// APPROACH
// 1. Do level order traversal
// 2. Instead of storing from left to right, track boolean varialbe turn:
//     a. IF turn == true: store from left to right
//     b. IF turn == false: store left to right

// TIME COMPLEXITY
// TC: O(n)

// SPACE COMPLEXITY
// TC: O(n) - for queue

// CODE

class Solution{
    public:
    vector <int> zigZagTraversal(Node* root) {
        vector<int> res;
        bool turn = 1;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int sz = q.size();
            vector<int> level;
            while(sz--) {
                Node *currNode = q.front(); q.pop();
                if(currNode -> left) q.push(currNode -> left);
                if(currNode -> right) q.push(currNode -> right);
                level.push_back(currNode -> data);
            }
            if(turn) res.insert(res.end(), level.begin(), level.end());
            else res.insert(res.end(), level.rbegin(), level.rend());
            turn = !turn;
        }
        
        return res;
    }
};