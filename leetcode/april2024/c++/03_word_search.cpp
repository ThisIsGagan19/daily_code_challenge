// CODE

class Solution {
    public:
    bool dfs(vector<vector<char>>& board, string& word, int index, int i, int j) {
        if(index >= word.size()) {
            return true;
        }
        
        if(i >= board.size() || i < 0 || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }
        
        char c = board[i][j];
        board[i][j] = '.';
        
        bool answer = dfs(board, word, index + 1, i - 1, j) ||
                      dfs(board, word, index + 1, i, j - 1) ||
                      dfs(board, word, index + 1, i + 1, j) ||
                      dfs(board, word, index + 1, i, j + 1);
        
        board[i][j] = c;
        return answer;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(board, word, 0, i, j))
                        return true;
                }
            }
        }
        return false;
    }
};