class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        unordered_set <char> uSet;
            
        // check each row
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(board[i][j] == '.') continue;
                if(uSet.find(board[i][j]) != uSet.end()) return false;
                uSet.insert(board[i][j]);
            }
            uSet.clear();
        }
        
        // check each column
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(board[j][i] == '.') continue;
                if(uSet.find(board[j][i]) != uSet.end()) return false;
                uSet.insert(board[j][i]);
            }
            uSet.clear();
        }
        
        // check each sub-box
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                for(int k = (i * 3); k < ((i + 1) * 3); ++k) {
                    for(int l = (j * 3); l < ((j + 1) * 3); ++l) {
                        if(board[k][l] == '.') continue;
                        if(uSet.find(board[k][l]) != uSet.end()) return false;
                        uSet.insert(board[k][l]);
                    }
                }
                uSet.clear();
            }
        }
        
        return true;
    }
};
