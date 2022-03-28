class Solution {
public:
    int longestPalindromeSubseq(string s) {

        if (s == "") return 0;
        size_t n = s.size();
        int f[n][n];
        fill_n(&f[0][0], n*n, 0);

        // vector<vector<int> > f(n, vector<bool>(n, false));
        int start = 0, max_length = 1;

        for (int i = 0; i < n; ++i) f[i][i] = 1;

        for (int i = n - 2; i > -1; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) f[i][j] = f[i + 1][j - 1] + 2;
                else f[i][j] = max(f[i + 1][j], f[i][j - 1]);

            }
        }
        return f[0][n - 1];
    }
};