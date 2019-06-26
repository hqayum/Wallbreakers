class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col) {
        if(row < 0 || row >= board.size()) return;
        if(col < 0 || col >= board[0].size()) return;
        if(board[row][col] == 'X') return;
        if(board[row][col] == 'A') return;
        
        board[row][col] = 'A';
        dfs(board, row + 1, col);
        dfs(board, row - 1, col);
        dfs(board, row, col + 1);
        dfs(board, row, col - 1);
    }
    
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if(rows <= 0) return;
        int cols = board[0].size();
        if(cols <= 0) return;
        
        for(int i = 0; i < rows; ++i) {
            dfs(board, i, 0);
            dfs(board, i, cols-1);
        }
        for(int i = 0; i < cols; ++i) {
            dfs(board, 0, i);
            dfs(board, rows-1, i);
        }
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
