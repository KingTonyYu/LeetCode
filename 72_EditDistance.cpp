class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = static_cast<int>(word1.size());
        int len2 = static_cast<int>(word2.size());
        if (!len1 || !len2) {
            return len1 ? len1 : len2;
        }

        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        for (int i = 0; i <= len1; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= len2; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                int val_plus = word1[i - 1] == word2[j - 1] ? 0 : 1;
                dp[i][j] = min(min(dp[i][j - 1] + 1, dp[i - 1][j] + 1), dp[i - 1][j - 1] + val_plus);
            }
        }
        return dp[len1][len2];

    }
};