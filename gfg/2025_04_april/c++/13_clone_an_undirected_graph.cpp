// CODE

class Solution {
    public:
      unordered_map<Node*, Node*> mp;
      Node* cloneGraph(Node* node) {
          if(node == NULL) return NULL;
          if(mp.find(node) != mp.end()) return mp[node];
          Node* cloneNode = new Node(node->val);
          mp[node] = cloneNode;
          for(auto it : node->neighbors){
              cloneNode->neighbors.push_back(cloneGraph(it));
          }
          return cloneNode;
      }
};