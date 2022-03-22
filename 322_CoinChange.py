class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0

        dp = [math.inf] * (amount + 1)
        dp[0] = 0

        for coin in coins:
          for i in range(coin, amount + 1):
            dp[i] = min(dp[i], dp[i - coin] + 1)

        if dp[amount] == math.inf:
            return -1

        return dp[amount] if dp[amount] != math.inf else -1