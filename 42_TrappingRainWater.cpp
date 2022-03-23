class Solution {
public:
    int trap(vector<int>& height) {
        int length = static_cast<int>(height.size());
        vector<int> stack;
        int ans = 0;
        for (int i = 0; i < length;) {
            if (stack.empty() || height[i] <= height[stack.back()]) {
                stack.push_back(i);
                i++;
            }
            else {
                int floor = height[stack.back()];
                stack.pop_back();
                if (stack.empty())
                    continue;
                int w = i - stack.back() - 1;

                int h = min(height[stack.back()], height[i]) - floor;
                ans += w * h;
            }
        }
        return ans;
    }
};