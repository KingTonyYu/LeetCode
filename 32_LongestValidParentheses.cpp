class Solution {
public:
    int longestValidParentheses(string s) {
        int length = static_cast<int>(s.size());
        vector<int> stack;
        int ans = 0;
        int start = 0;
        for (int i = 0; i < length; i++) {
            if (s[i] == '(') {
                stack.push_back(i);
                continue;
            }

            if (stack.empty()) {
                start = i + 1;
                continue;
            }

            int last = stack.back();
            stack.pop_back();
            if (stack.empty()) {
                ans = max(ans, i - start + 1);
            } else
                ans = max(ans, i - stack.back());
        }
        return ans;
    }
};