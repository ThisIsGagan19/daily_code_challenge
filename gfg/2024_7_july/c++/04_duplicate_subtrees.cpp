// TIME COMPLEXITY
// O(n^2)

// SPACE COMPLEXITY
// O(n^2)

// CODE

class Solution {
  public:
    unordered_map<string, int> m;
    vector<Node*> v;
    string count(Node *r) {
            if(!r) return "";
            
            string x = count(r->left) + "," + to_string(r->data) + "," + count(r->right);
            
            ++m[x];
            
            if(m[x] == 2) v.push_back(r);
            
            return x;
    }
    vector<Node*> printAllDups(Node *r) {
            return count(r), v;
    }
};