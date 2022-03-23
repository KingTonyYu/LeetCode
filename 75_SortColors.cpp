class Solution {
public:
    void sortColors(vector<int>& nums) {
        int length = static_cast<int>(nums.size());
        int left = 0;
        int right = length - 1;
        for (int i = 0; i <= right; i++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[left]);
                left++;
            }
            else if (nums[i] == 2) {
                swap(nums[i], nums[right]);
                right--;
                i--;
            }
        }
    }
};