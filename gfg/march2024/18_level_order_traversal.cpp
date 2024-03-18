// INTUITION
// For every node we have to take its left child then right child and to 
// maintain storing order we can use queue. Hence, we can achieve left to 
// right level order traversal.

// APPROACH
// 1. Take queue.
// 2. Take element from queue and push into result. 
// 3. For the each element taken from queue's front push its left and right 
//    element (if exists) in order, until the queue becomes empty.
// 4. Finally, return the resulted array/vector.

// TIME COMPLEXITY
// TC: O(heightOfTree) | O(n) - worst case

// SPACE COMPLEXITY
// SC: O(n)

// CODE

class Solution {
    public:
    vector<int> levelOrder(Node* root) {
        vector<int> res;
        if(root == NULL) return {};
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node *currNode = q.front(); q.pop();
            res.push_back(currNode -> data);
            if(currNode -> left) q.push(currNode -> left);
            if(currNode -> right) q.push(currNode -> right);
        }
        return res;
    }
};