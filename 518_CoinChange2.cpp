class Solution {
public:
    int change(int amount, vector<int>& coins) {
      int dp_length = amount + 1;
      
      vector<int> dp(dp_length, 0);
      dp[0] = 1;
      
      for (const auto& coin : coins) {
        for (int i = coin; i < dp_length; i++) {
          dp[i] += dp[i - coin];
        }
      }
      return dp[amount];
    }
  
};