class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        multiset<pair<int, int>> scan_lines;
        vector<int> ans;
        int max_height = 0;

        for (const auto& position : positions) {
            int left = position[0];
            int height = position[1];
            int right = left + height;
            auto it = scan_lines.upper_bound({left, 0});
            if (it != scan_lines.begin())
                it = prev(it);
            int base_height = 0;
            int cur_height = 0;
            while (it != scan_lines.end() && it->first < right) {
                cur_height = it->second;
                base_height = max(base_height, cur_height);  
                if (it->first < left) {
                     it++;
                    continue;
                }

                it = scan_lines.erase(it);
            }

            if (it == scan_lines.end()) {
                scan_lines.insert({right, 0});
            }
            else {
                scan_lines.insert({right, cur_height});
            }

            scan_lines.insert({left, base_height + height});
            max_height = max(max_height, base_height + height);
            ans.push_back(max_height);

        }
        return ans;
    }
};