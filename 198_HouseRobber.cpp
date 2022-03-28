class Solution {
public:
    int rob(vector<int>& nums) {
        int length = static_cast<int>(nums.size());
        vector<int> dp(length + 1);
        dp[0] = 0;
        dp[1] = nums[0];
        if (length == 1)
            return nums[0];

        for (int i = 1; i < length; i++) {
            dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
        }
        return dp[length];
    }
};