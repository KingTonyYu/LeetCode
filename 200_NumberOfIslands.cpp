class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') continue;
                dfs(grid, i, j, m, n);
                ans++;
            }
        }

        return ans;
    }

    void dfs(vector<vector<char>>& grid, int row, int col, int m, int n) {
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == '0')
            return;
        grid[row][col] = '0';
        dfs(grid, row + 1, col, m, n);
        dfs(grid, row, col + 1, m, n);
        dfs(grid, row - 1, col, m, n);
        dfs(grid, row, col - 1, m, n);
    }
};