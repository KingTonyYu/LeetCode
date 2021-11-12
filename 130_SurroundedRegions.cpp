class Solution {
private:
  char marker_island = 'O';
  char marker_sea = 'X';
  char marker_border = 'B';
  vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
public:
  void solve(vector<vector<char>>& board) {
    detectBorder(board);
    modifyBoard(board, marker_island, marker_sea);   
    modifyBoard(board, marker_border, marker_island);
  }
  
  void detectBorder(vector<vector<char>>& board)
  {
    int height = board.size();
    int width = board[0].size();
    vector<pair<int, int>> border_pairs = getBorderPositions(board);
    for (const auto& pair : border_pairs) {
      if (board[pair.first][pair.second] == marker_island) {
        bfsToModifyBoard(board, border_pairs, marker_island, marker_border);
      }
    }
  }
  
  vector<pair<int, int>> getBorderPositions(vector<vector<char>>& board) {
    vector<pair<int, int>> result;
    int height = board.size();
    int width = board[0].size();
    for (int col = 0; col < width; col++) {
      result.emplace_back(0, col);
      result.emplace_back(height - 1, col);
    }
    for (int row = 0; row < height; row++) {
      result.emplace_back(row, 0);
      result.emplace_back(row, width - 1);
    }
    return result;
  }
  
  void bfsToModifyBoard(vector<vector<char>>& board, const vector<pair<int, int>>& border_pairs, const char marker_to_replace, const char marker_replacement) {
    int height = board.size();
    int width = board[0].size();
    deque<pair<int, int>> queue;
    for_each(border_pairs.begin(), border_pairs.end(), [&queue](const auto& pair) {queue.push_back(pair);});
    while (!queue.empty()) {
      auto pair = queue.front();
      queue.pop_front();
      int row = pair.first;
      int col = pair.second;
      if (board[row][col] != marker_to_replace)
        continue;
      board[row][col] = marker_replacement;
      for (const auto& direction : directions) {
        int new_row = row + direction[0];
        int new_col = col + direction[1];
        if (new_row >= 0 && new_row < height
          && new_col >= 0 && new_col < width) {
          queue.emplace_back(new_row, new_col);
        }
      }
    }
  }

  void modifyBoard(vector<vector<char>>& board, const char marker_to_replace, const char marker_replacement)
  {
    int height = board.size();
    int width = board[0].size();
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        if (board[i][j] == marker_to_replace) {
          board[i][j] = marker_replacement;
        }
      }
    }
  }
};