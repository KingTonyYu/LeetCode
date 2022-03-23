class Solution {
private:
    int height;
    int width;
public:
    bool exist(vector<vector<char>>& board, string word) {
        height = board.size();
        width = board[0].size();
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (board[i][j] == word[0]) {
                    if (helper(board, i, j, word, 0))
                        return true;
                }
            }
        }
        return false;
    }

    bool helper(vector<vector<char>>& board, int i, int j, string word, int idx) {
        if (idx == word.size())
            return true; 
        if (i >= height || i < 0 || j >= width || j < 0)
            return false;

        if (board[i][j] != word[idx])
            return false;

        char cur = board[i][j];
        board[i][j] = '0';
        bool result = helper(board, i + 1, j, word, idx + 1)
                    || helper(board, i, j + 1, word, idx + 1)
                    || helper(board, i - 1, j, word, idx + 1)
                    || helper(board, i, j - 1, word, idx + 1);
        board[i][j] = cur;
        return result;
    }
};