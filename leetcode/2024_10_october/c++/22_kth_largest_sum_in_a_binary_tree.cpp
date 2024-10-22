// CODE

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long , vector<long long> , greater<long long> > minHeap;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            long long lvlSum = 0;
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* frontNode = q.front();
                q.pop();
                lvlSum += frontNode->val;
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }
            minHeap.push(lvlSum);
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        if(minHeap.size() < k) return -1;
        return minHeap.top();
    }
};