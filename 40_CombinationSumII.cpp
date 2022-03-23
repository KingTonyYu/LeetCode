class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int length = static_cast<int>(candidates.size());
        sort(candidates.begin(), candidates.end());
        vector<int> cur_list;

        function<void(int, int)> dfsHelper = [&](int cur_target, int cur_loc) {
            if (cur_target == 0) {
                ans.push_back(cur_list);
                return;
            }

            for (int i = cur_loc; i < length; i++) {
                if (i > cur_loc && candidates[i] == candidates[i - 1])
                    continue;
                if (cur_target - candidates[i] < 0)
                    break;
                cur_list.push_back(candidates[i]);
                dfsHelper(cur_target - candidates[i], i + 1);
                cur_list.pop_back();
            }
        };
        dfsHelper(target, 0);
        return ans;
    }
};