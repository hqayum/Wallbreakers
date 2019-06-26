class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col) {
        if(row < 0 || row >= grid.size()) return;
        if(col < 0 || col >= grid[0].size()) return;
        if(grid[row][col] == '0') return;
        
        grid[row][col] = '0';
        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows <= 0) return 0;
        int cols = grid[0].size();
        if(cols <= 0) return 0;
        
        
        int numOfIslands = 0;
        //vector<char> islands(cols);
        //for(int i = 0; i < cols; ++i) islands[i] = i;
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(grid[i][j] == '1') {
                    ++numOfIslands;
                    dfs(grid, i, j);
                }
            }
        }
        return numOfIslands;
    }
};
