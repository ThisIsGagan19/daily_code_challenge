// TIME COMPEXITY
// O(wordLength + k)

// SPACE COMPEXITY
// O(wordLength + k)

// CODE

class Solution{
    public:
    string findOrder(string dict[], int n, int k) {
        vector<int> adj[k];
        vector<int> indegree(k);
        
        for(int i = 0; i < n-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int size = min(s1.length(),s2.length());
            for(int j = 0; j < size; j++){
                if(s1[j] != s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j] - 'a');
                    indegree[s2[j]-'a']++;
                    break;
                }
            }
        }
        
        queue<int> q;
        for(int i = 0; i < k; i++){
            if(indegree[i] == 0) q.push(i);
        }
        string res;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            res.push_back(char(frontNode + 'a'));
            for(int node : adj[frontNode]){
                indegree[node]--;
                if(indegree[node] == 0) q.push(node);
            }
        }
        return res;
    }
};