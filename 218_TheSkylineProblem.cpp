class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        typedef std::vector<int> event_t;
        std::function<bool(const event_t&, const event_t&)> sort_helper = [](const event_t& p1, const event_t& p2) {
            if (p1[0] == p2[0])
                return p1[1] > p2[1];
            return p1[0] < p2[0];
        };

        std::function<int(const std::multiset<int>&)> max_height = [](const std::multiset<int>& bst) {
            if (bst.empty()) {
                return 0;
            }
            return *bst.rbegin();
        };

        std::multiset<int> bst;
        std::vector<event_t> event_list;
        std::vector<event_t> ans;

        for (const auto& building : buildings) {
            event_list.push_back({building[0], building[2]});
            event_list.push_back({building[1], -building[2]});
        }

        std::sort(event_list.begin(), event_list.end(), sort_helper);
        for (const auto& event : event_list) {
            int position = event[0];
            int height = std::abs(event[1]);
            bool entering = event[1] > 0;
            if (entering) {
                if (height > max_height(bst)) {
                    ans.push_back({position, height});
                }
                bst.insert(height);
            }
            else {
                // bst.erase(bst.find(height));
                bst.erase(bst.equal_range(height).first);
                if (height > max_height(bst)) {
                    ans.push_back({position, max_height(bst)});
                }
            }
        }
        return ans;
    }
};