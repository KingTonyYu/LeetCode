class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hash;
        for (const auto& word : words) {
            hash[word]++;
        }

        auto compair = [](pair<string, int> p1, pair<string, int> p2) {
            if (p1.second == p2.second)
                return p1.first > p2.first;
            return p1.second < p2.second;
        };

        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(compair)> queue(compair);

        for (const auto& p : hash) {
            queue.push(p);
        }
        vector<string> ans;
        for (int i = 0; i < k; i++) {
            auto p = queue.top();
            queue.pop();
            ans.push_back(p.first);
        }
        return ans;
    }
};