class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int height = static_cast<int>(image.size());
        int width = static_cast<int>(image[0].size());
        int oldColor = image[sr][sc];
        if (oldColor == newColor)
            return image;

        function<void(int, int)> dfs_helper = [&](int row, int col) {
            if (row < 0 || row >= height)
                return;
            if (col < 0 || col >= width)
                return;
            if (image[row][col] != oldColor)
                return;
            // cout << row << " " << col << " " << oldColor << " " << image[row][col] << endl;
            image[row][col] = newColor;
            dfs_helper(row + 1, col);
            dfs_helper(row - 1, col);
            dfs_helper(row, col + 1);
            dfs_helper(row, col - 1);
        };

        dfs_helper(sr, sc);
        return image;
    }
};