class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folders) {
        unordered_set<string> paths(folders.begin(), folders.end());
        vector<string> ans;

        for (const auto& folder : folders) {
            string cur = folder;
            bool valid = true;
            while (!cur.empty() && valid) {
                while (cur.back() != '/') {
                    cur.pop_back();
                }
                cur.pop_back();
                if (paths.find(cur) != paths.end()) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ans.push_back(folder);
            }
        }
        return ans;
    }
};