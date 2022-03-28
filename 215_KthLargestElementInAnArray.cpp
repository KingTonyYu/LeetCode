class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        function<int(int, int, int)> quickSort = [&](int start, int end, int kth) {
            if (start == end) {
                return nums[start];
            }

            int left = start;
            int right = end;
            int mid = start + (end - start) / 2;
            int prio = nums[mid];

            while (left <= right) {
                while (left <= right && nums[left] > prio)
                    left++;
                while (left <= right && nums[right] < prio)
                    right--;
                if (left > right)
                    break;
                swap(nums[left], nums[right]);
                left++;
                right--;
            }

            if (start + kth - 1 <= right)
                return quickSort(start, right, kth);
            if (start + kth - 1 >= left)
                return quickSort(left, end, kth - left + start);
            return nums[right + 1];
        };

        int length = static_cast<int>(nums.size());
        return quickSort(0, length - 1, k);
    }
};