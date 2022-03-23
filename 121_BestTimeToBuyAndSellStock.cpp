class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int num_day = prices.size();
        std::vector<std::vector<int>> dp(num_day, std::vector(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < num_day; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], - prices[i]);
        }
        return dp[num_day - 1][0];
    }
};