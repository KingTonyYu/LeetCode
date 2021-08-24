#include "common_header.h"

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        if (height.empty())
            return 0;
        
        int left = 0;
        int right = height.size() - 1;
        int max_val = 0;
        while (left < right)
        {
            max_val = max(max_val, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return max_val;
        
    }
};