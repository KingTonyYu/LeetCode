class Solution {
public:
  bool canJump(vector<int>& nums) {
    int target = nums.size() - 1;
    for (int i = target; i > -1; i--) {
      if (i + nums[i] >= target) {
        target = i;
      }
    }
    return target == 0;
  }
};