class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int height = static_cast<int>(grid.size());
        int width = static_cast<int>(grid[0].size());
        typedef deque<pair<int, int>> queue_t;
        queue_t queue;
        const int visited_val = 2;
        const int sea_val = 0;
        const int land_val = 1;

        function<void(const int, const int)> dfs_helper = [&](const int x, const int y) {
            if (x < 0 || x >= height || y < 0 || y >= width || grid[x][y] != land_val)
                return;
            grid[x][y] = visited_val;
            queue.emplace_back(x, y);
            dfs_helper(x, y + 1);
            dfs_helper(x + 1, y);
            dfs_helper(x, y - 1);
            dfs_helper(x - 1, y);
            return;
        };

        function<int(void)> bfs_helper = [&]() {
            int counter = 0;
            while (!queue.empty()) {
                int queue_length = static_cast<int>(queue.size());
                for (int i = 0; i < queue_length; i++) {
                    auto cur_node = queue.front();
                    queue.pop_front();
                    for (const auto& direct : directions) {
                        int tmp_first = cur_node.first + direct.first;
                        int tmp_second = cur_node.second + direct.second;
                        if (tmp_first < 0 || tmp_first >= height || tmp_second < 0 || tmp_second >= width) {
                            continue;
                        }
                        if (grid[tmp_first][tmp_second] == visited_val) {
                            continue;
                        }
                        if (grid[tmp_first][tmp_second] == land_val) {
                            return counter;
                        }
                        grid[tmp_first][tmp_second] = visited_val;
                        queue.emplace_back(tmp_first, tmp_second);
                    }
                };
                counter++;
            }
            return -1;
        };

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == 1) {
                    dfs_helper(i, j);
                    return bfs_helper();
                }
            }
        }
        return -1;
    }
};