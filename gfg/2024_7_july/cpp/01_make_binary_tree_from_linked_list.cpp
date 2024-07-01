// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(n)

// CODE

void convert(Node *head, TreeNode *&root) {
    vector<TreeNode*> tree;
    Node *temp = head;
    while(temp != NULL){
        tree.push_back(new TreeNode(temp->data));
        temp = temp -> next;
    }
    for(int i = 0; i < tree.size(); i++){
        int left = 2*i + 1;
        int right = 2*i + 2;
        if(left < tree.size()){
            tree[i] -> left = tree[left];
        }
        if(right < tree.size()){
            tree[i] -> right = tree[right];
        }
    }
    root = tree[0];
}