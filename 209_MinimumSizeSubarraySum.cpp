class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int length = nums.size();
        int cur_sum = 0;
        nums.push_back(0);
        int ans = length + 1;

        while (right <= length) {
            if (cur_sum < target) {
                cur_sum += nums[right];
                right++;
            } else {
                ans = min(ans, right - left);
                cur_sum -= nums[left];
                left++;
            }
        }
        return ans == length + 1 ? 0 : ans;
    }
};