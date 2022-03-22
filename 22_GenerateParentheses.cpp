class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int cur_left = 1;
        int cur_score = 1;
        string cur_str = "(";
        vector<string> result;

        function<void(void)> dfs_helper = [&](){
            if (cur_left == n) {
                result.push_back(complementParentheses(cur_str, cur_score));
                return;
            }
            if (cur_score > 0) {
                cur_score--;
                cur_str.push_back(')');
                dfs_helper();
                cur_score++;
                cur_str.pop_back();
            }
            cur_left++;
            cur_score++;
            cur_str.push_back('(');
            dfs_helper();
            cur_left--;
            cur_score--;
            cur_str.pop_back();
        };
        dfs_helper();
        return result;
    }

    string complementParentheses(const string& cur_str, int cur_score) {
        string ans = cur_str;
        for (int i = 0; i < cur_score; i++) {
            ans.push_back(')');
        }
        return ans;
    }
};