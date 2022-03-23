class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int N = prices.size();
        int dp[N][2];
        int max_rev = 0;
        for (int i = 0; i < N; i++) {
            dp[i][0] = 0;
            dp[i][1] = INT_MIN;
        }
        dp[0][1] = -prices[0];

        for (int i = 1; i < N; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[N - 1][0];
    }
};