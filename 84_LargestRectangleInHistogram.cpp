class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int length = static_cast<int>(heights.size());

        vector<int> mono_stack;
        int max_area = 0;
        int i = 0;
        while (i < length) {
            if (mono_stack.empty() || heights[mono_stack.back()] <= heights[i]) {
                mono_stack.push_back(i);
                i++;
            }
            else {
                int h = heights[mono_stack.back()];
                mono_stack.pop_back();
                int w = mono_stack.empty() ? i : i - mono_stack.back() - 1;

                max_area = max(max_area, h * w);                
            }
        }
        return max_area;
    }

};