// INTUITION
// We can go in right direction there isn't any problem in that, point is how
// to track left nodes at that time. well, think of storing them in some data
// structure like queue or stack. Next time pick nodes from that data structure
// and do the same.

// APPROACH
// 1. Move in right direction from root as far as we can go
// 2. If left subtree exists for some nodes, store it in queue
// 3. Now, for that particular size/level of queue do the same for all nodes
//    present in queue
//    For all nodes in queue, pick one node traverse as far as we can go and store
//    left subtree root in queue
// 4. Maintain sum for each size/level
// 5. Store sum in result vector and return result

// TIME COMPLEXITY
// TC: O(n)

// SPACE COMPLEXITY
// SC: O(n)

// CODE

class Solution {
    public:
    vector <int> diagonalSum(Node* root) {
        vector<int> res;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int sz = q.size();
            int sum = 0;
            while(sz--) {
                Node *currNode = q.front(); q.pop();
                while(currNode) {
                    if(currNode -> left) q.push(currNode -> left);
                    sum += currNode -> data;
                    currNode = currNode -> right;
                }
            }
            res.push_back(sum);
        }
        
        return res;
    }
};