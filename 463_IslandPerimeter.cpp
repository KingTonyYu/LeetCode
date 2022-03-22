class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
      int height = static_cast<int>(grid.size());
      int width = static_cast<int>(grid[0].size());
      int perimeter = 0;
      for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
          if (grid[row][col] == 0)
            continue;
          perimeter += 4;

          if (row > 0 && grid[row - 1][col] == 1)
            perimeter -= 2;
          if (col > 0 && grid[row][col - 1] == 1)
            perimeter -= 2;
        }
      }
      return perimeter;
    }
};