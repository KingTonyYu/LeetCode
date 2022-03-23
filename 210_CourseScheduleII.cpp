class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 1)
            return {0};
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);

        for (const auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        vector<int> ans;
        queue<int> queue;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                queue.push(i);
        }

        while (!queue.empty()) {
            int cur = queue.front();
            ans.push_back(cur);
            queue.pop();
            for (const auto& i : graph[cur]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    queue.push(i);
            }
        }

        if (ans.size() != numCourses)
            return {};
        return ans;

    }
};