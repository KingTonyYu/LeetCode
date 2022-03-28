class Solution {
public:
    int reversePairs(vector<int>& nums) {

        function<void(int, int, int, int)> mergeTwolist = [&](int start1, int end1, int start2, int end2) {
            int length = end2 - start1 + 1;
            vector<int> ans(length);
            int pos1 = start1;
            int pos2 = start2;
            auto it = ans.begin();
            while (pos1 <= end1 && pos2 <= end2) {
                if (nums[pos1] < nums[pos2]) {
                    *it = nums[pos1];
                    pos1++;
                } else {
                    *it = nums[pos2];
                    pos2++;
                }
                it++;
            }
            if (pos1 <= end1) {
                copy(nums.begin() + pos1, nums.begin() + end1 + 1, it);
            } else {
                copy(nums.begin() + pos2, nums.begin() + end2 + 1, it);
            }
            copy(ans.begin(), ans.end(), nums.begin() + start1);
        };

        function<int(int, int)> mergeSortAndGetPairs = [&](int start, int end) {
            if (start >= end)
                return 0;
            int mid = start + (end - start) / 2;
            int left_count = mergeSortAndGetPairs(start, mid);
            int right_count = mergeSortAndGetPairs(mid + 1, end);

            int pos1 = mid;
            int pos2 = end;
            int cur_count = 0;

            while (pos1 >= start && pos2 > mid) {
                if (static_cast<double>(nums[pos1]) / 2.0 > nums[pos2]) {
                    cur_count += pos2 - mid;
                    pos1--;
                } else {
                    pos2--;
                }
            }

            mergeTwolist(start, mid, mid + 1, end);

            return left_count + right_count + cur_count;
        };

        return mergeSortAndGetPairs(0, static_cast<int>(nums.size()) - 1);
    }

};