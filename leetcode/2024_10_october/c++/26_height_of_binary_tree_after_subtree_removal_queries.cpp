// CODE

class Solution {
public:
    int dfs(TreeNode* root,vector<int> &ht){
        if(root==NULL){
            return -1;
        }
        return ht[root->val]=1+max(dfs(root->left,ht),dfs(root->right,ht));
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& qr) {
        vector<int> ht(1e5+1,0),lvl(1e5+1,-1);
        dfs(root,ht);

        vector<priority_queue<pair<int,int>>> vpq;
        //queue for level order traversal
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            priority_queue<pair<int,int>> pq;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();
                q.pop();
                lvl[node->val]=level;
                //push pair of (height of node , node)
                pq.push({ht[node->val],node->val});
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            level++;
            //push ith level pq in vpq
            vpq.push_back(pq);
        }
        vector<int> ans;
        //height of root
        int rootht=ht[root->val];
        for(auto i:qr){
            // top node in pq of the ith level
            auto tp=vpq[lvl[i]].top();
            if(tp.second==i){
                //case 1
                vpq[lvl[i]].pop();
                if(vpq[lvl[i]].size()==0){
                    //sub case 1:
                    //there is no other best node on the ith level
                    //just remove the height of top node(tp.first)
                    //also remove connection with top node(-1)
                    ans.push_back(rootht-tp.first-1);
                }
                else{
                    //sub case 2:
                    //there is a second best node on ith level
                    // remove the height of top node(tp.first)
                    //also add the height os second best node(vpq[lvl[i]].top().first)
                    ans.push_back(rootht-tp.first+vpq[lvl[i]].top().first);
                }
                vpq[lvl[i]].push(tp);
            }
            else{
                //case 2
                ans.push_back(rootht);
            }
        }
        return ans;
    }
};