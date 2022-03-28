class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int length = static_cast<int>(piles.size());
        vector<int> dp(length);
        for (int i = 0; i < length; i++) {
            dp[i] = piles[i];
        }

        for (int i = length - 1; i >= 0; i--) {
            for (int j = i + 1; j < length; j++) {
                dp[i] = max(piles[i] - dp[i + 1], piles[j] - dp[i]);
            }
        }
        return dp[length - 1] > 0;
    }
};