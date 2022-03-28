class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in_degree(numCourses);
        vector<vector<int>> children(numCourses);
        for (const auto& p : prerequisites) {
            children[p[1]].push_back(p[0]);
            in_degree[p[0]]++;
        }
        queue<int> active;
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0)
                active.push(i);
        }
        while (!active.empty()) {
            numCourses--;
            int cur = active.front();
            active.pop();
            for (int child : children[cur]) {
                in_degree[child]--;
                if (in_degree[child] == 0)
                    active.push(child);
            }
        }
        return numCourses == 0;
    }
};