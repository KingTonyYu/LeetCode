class Solution {
public:
    int search(vector<int>& nums, int target) {

        function<int(int, int)> helper = [&](int start, int end) {
;
            if (start == end && target == nums[start])
                return start;
            if (start >= end)
                return -1;
            int mid = start + (end - start) / 2;
            if (nums[start] < nums[end]) {
                if (nums[start] <= target && target <= nums[mid])
                    return helper(start, mid);
                else
                    return helper(mid + 1, end);
            }
            else if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target <= nums[mid])
                    return helper(start, mid);
                else
                    return helper(mid + 1, end);
            }
            else {
                if (target >= nums[0] || target <= nums[mid])
                    return helper(start, mid);
                else
                    return helper(mid + 1, end);                    
            }
            return -1;
        };

        return helper(0, static_cast<int>(nums.size())- 1);
    }
};