// TIME COMPEXITY
// O(m * n)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int> (n, -1));

        int top = 0;
        int down = m - 1;
        int left = 0;
        int right = n - 1;

        int id = 0;

        while(top <= down && left <= right){
            if(id == 0){ // left -> right
                for(int i = left; i <= right && head != NULL; i++){
                    ans[top][i] = head->val;
                    head = head->next;
                }
                id = (id + 1) % 4;
                top++;
            }
            else if(id == 1){ // top -> down
                for(int i = top; i <= down && head != NULL; i++){
                    ans[i][right] = head->val;
                    head = head->next;
                }
                id = (id + 1) % 4;
                right--;
            }
            else if(id == 2){ // right -> left
                for(int i = right; i >= left && head != NULL; i--){
                    ans[down][i] = head->val;
                    head = head->next;
                }
                id = (id + 1) % 4;
                down--;
            }
            else{ // down -> top
                for(int i = down; i >= top && head != NULL; i--){
                    ans[i][left] = head->val;
                    head = head->next;
                }
                id = (id + 1) % 4;
                left++;
            }
        }
        return ans;
    }
};