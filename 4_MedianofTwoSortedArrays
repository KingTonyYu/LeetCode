class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = static_cast<int>(nums1.size() + nums2.size());
        if (n == 0)
            return -1.0;
        return static_cast<double>(getKthDoubleArray(nums1, nums2, 0, 0, (n + 1) / 2.0) + getKthDoubleArray(nums1, nums2, 0, 0, (n + 2) / 2)) / 2.0;
        
    }
    
    int getKthDoubleArray(const vector<int>& nums1, const vector<int>& nums2, int nums1_start, int nums2_start, int k)
    {
        if (nums1_start >= static_cast<int>(nums1.size()))
            return nums2[nums2_start + k - 1];
        else if (nums2_start >= static_cast<int>(nums2.size()))
            return nums1[nums1_start + k - 1];
        else if (k == 1)
            return min(nums1[nums1_start], nums2[nums2_start]);
        else
        {
            if (getKthSingleArray(nums1, nums1_start + k / 2 - 1) < getKthSingleArray(nums2, nums2_start + k / 2 - 1))
                return getKthDoubleArray(nums1, nums2, nums1_start + k / 2, nums2_start, k - k / 2);
            else
                return getKthDoubleArray(nums1, nums2, nums1_start, nums2_start + k / 2, k - k / 2);
        }
        return -1;
    }
    
    int getKthSingleArray(const vector<int>& nums, int k)
    {
        if (k >= static_cast<int>(nums.size()))
            return INT_MAX;
        return nums[k];
    }

};
