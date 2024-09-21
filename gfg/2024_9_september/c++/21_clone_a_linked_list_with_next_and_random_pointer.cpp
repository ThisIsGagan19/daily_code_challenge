// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(n)

// CODE

class Solution
{
    private:
        void insertAtTail(Node * &head,Node * &tail,int d){
            Node* temp = new Node(d);
            if(head == NULL){
                head = temp;
                tail = temp;
                return ;
            }
            else{
                tail->next = temp;
                tail = temp;
            }
        }
    public:
    Node *copyList(Node *head)
    {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        // step 1 make a clone LL of orginal LL
        Node* temp = head;
        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail,temp->data);
            temp = temp->next;
        }
        
        // step 2 create map for mapping the original node to clone node
        unordered_map<Node*,Node*> oldToNew;
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL){
            oldToNew[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        
        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode != NULL){
            cloneNode->random = oldToNew[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        return cloneHead;
    }
};