class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        if (A.empty() || A[0].empty()) return 0;

        int row_num = A.size();
        int col_num = A[0].size();

        for (int i = 0; i < row_num; i++) {
            if (A[i][0] == 1) continue;
            rowFlip(A, i);
        }

        for (int j = 0; j < col_num; j++) {
            if (colOneCount(A, j) > (row_num / 2)) continue;
            colFlip(A, j);
        }

        return binarySum(A);
    }

    int colOneCount(vector<vector<int>>& A, int col) {
        int ans = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i][col] == 1) ans++;
        }
        return ans;
    }

    void rowFlip(vector<vector<int>>& A, int row) {
        for (int j = 0; j < A[0].size(); j++) {
            A[row][j] = (A[row][j] == 1) ? 0 : 1; 
        }
    }

    void colFlip(vector<vector<int>>& A, int col) {
        for (int i = 0; i < A.size(); i++) {
            A[i][col] = (A[i][col] == 1) ? 0 : 1; 
        }
    }

    int binarySum(const vector<vector<int>>& A) {
        int ans = 0;
        int row_num = A.size();
        int col_num = A[0].size();

        for (int j = 0; j < col_num; j++) {
            int factor = pow(2, col_num - 1 - j);
            int num = 0;
            for (int i = 0; i < row_num; i++) {
                num += A[i][j];
            }
            ans += factor * num;
        }
        return ans;
    }
};