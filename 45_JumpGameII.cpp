class Solution {
public:
  int jump(vector<int>& nums) {
    int length = static_cast<int>(nums.size());
    int counter = 0;
    int cur_range = 0;
    int cur_end = 0;
    for (int i = 0; i < length - 1; i++) {
      cur_range = max(nums[i] + i, cur_range);
      if (cur_range >= length - 1)
        return counter + 1;
      if (i == cur_end) {
        cur_end = cur_range;
        counter++;
      }
    }
    return counter;
  }
};