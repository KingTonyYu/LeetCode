class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int length = static_cast<int>(nums.size());
        unordered_map<int, int> map{{0, 1}};
        int ans = 0;
        int presum = 0;
        for (int i = 0; i < length; i++) {
            presum += nums[i];
            ans += map[presum - k];
            map[presum] += 1;
        }
        return ans;
    }
};