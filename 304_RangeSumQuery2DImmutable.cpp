class NumMatrix {
private:
    vector<vector<int> > sum_mat;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int height = static_cast<int>(matrix.size());
        int width = static_cast<int>(matrix[0].size());
        sum_mat = vector<vector<int> >(height + 1, vector<int>(width + 1));

        for (int i = 1; i <= height; i++) {
            for (int j = 1; j <= width; j++) {
                sum_mat[i][j] = matrix[i - 1][j - 1] \
                    - sum_mat[i - 1][j - 1] \
                    + sum_mat[i][j - 1] \
                    + sum_mat[i - 1][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {

        return sum_mat[row2 + 1][col2 + 1] - \
            sum_mat[row1][col2 + 1] - \
            sum_mat[row2 + 1][col1] + \
            sum_mat[row1][col1];
    }
};