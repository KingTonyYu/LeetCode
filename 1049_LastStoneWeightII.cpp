class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (const int& stone : stones) {
            sum += stone;
        }
        int target = sum / 2;
        vector<bool> dp(target + 1);
        dp[0] = true;
        for (const int& stone : stones) {
            for (int i = target; i >= 0; i--) {
                if (i + stone > target)
                    continue;
                dp[i + stone] = dp[i + stone] || dp[i];             
            }
            if (dp[target])
                break;
        }
        for (int i = target; i >= 0; i--) {
            if (dp[i])
                return sum - 2 * i;
        }
        return 0;
    }
};