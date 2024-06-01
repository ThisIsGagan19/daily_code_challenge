# CODE

class Solution:
    def dfs(self, board, word, index, i, j):
        if index >= len(word):
            return True
        
        if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]) or board[i][j] != word[index]:
            return False
        
        c = board[i][j]
        board[i][j] = '.'
        
        answer = self.dfs(board, word, index + 1, i - 1, j) or \
                 self.dfs(board, word, index + 1, i, j - 1) or \
                 self.dfs(board, word, index + 1, i + 1, j) or \
                 self.dfs(board, word, index + 1, i, j + 1)
        
        board[i][j] = c
        
        return answer
    
    def exist(self, board, word):
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == word[0]:
                    if self.dfs(board, word, 0, i, j):
                        return True
        return False   