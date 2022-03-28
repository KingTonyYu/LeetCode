class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int num_right = 0;
        for (const auto& c : s) {
            if (c == ')')
                num_right++;
        }
        int num_left = 0;
        string ans;
        for (const auto& c : s) {
            if (c == '(') {
                if (num_left == num_right)
                    continue;
                num_left++;
            }
            else if (c == ')') {
                num_right--;
                if (num_left == 0)
                    continue;
                num_left--;
            }
            ans.push_back(c);
        }
        return ans;
    }
};