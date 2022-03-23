class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0};

        vector<unordered_set<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);

        }

        vector<int> leaves;

        for (int i = 0; i < n; i++) {
            if (graph[i].size() == 1) {
                leaves.push_back(i);
            }
        }

        while (n > 2) {
            n -= leaves.size();
            vector<int> new_leaves;
            for (int leave : leaves) {
                int neighbor = *graph[leave].begin();
                graph[neighbor].erase(leave);

                if (graph[neighbor].size() == 1) {
                    new_leaves.push_back(neighbor);
                }
            }
            leaves = new_leaves;
        }

        return leaves;
    }
};