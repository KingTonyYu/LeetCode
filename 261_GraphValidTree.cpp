class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int edge_length = static_cast<int>(edges.size());
        if (edge_length != n - 1)
            return false;

        vector<vector<int>> relations(n);
        for (const auto& edge : edges) {
            relations[edge[0]].push_back(edge[1]);
            relations[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);

        function<void(int)> dfs_helper = [&](int cur_node) {
            if (visited[cur_node])
                return;
            visited[cur_node] = true;
            for (int node : relations[cur_node]) {
                dfs_helper(node);
            }
        };

        dfs_helper(0);
        for (auto flag : visited) {
            if (!flag)
                return false;
        }
        return true;
    }
};