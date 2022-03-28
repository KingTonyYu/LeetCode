class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for_each(nums.begin(), nums.end(), [&](int i) { sum += i;});
        if (sum % 2 == 1)
            return false;
        int target = sum / 2;
        vector<int> dp(target + 1, false);
        dp[0] = true;

        for (auto num : nums) {
            for (int i = target; i >= 0; i--) {
                if (i + num > target)
                    continue;
                if (dp[i + num])
                    continue;
                if (dp[i] && i + num <= target)
                    dp[i + num] = true;

            }
            if (dp[target])
                return true;
        }
        return false;
    }
};