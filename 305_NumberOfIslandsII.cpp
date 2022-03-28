class Solution {
public:
    class UnionFind {
    private:
        int count_;
        vector<int> parents_;
    public:
        UnionFind(int n) : count_(0), parents_(n, -1) {}
        void makeUnion(int a, int b) {
            int a_root = find(a);
            int b_root = find(b);
            if (a_root == b_root)
                return;
            parents_[a_root] = b_root;
            count_--;
        }
        void setParent(int x) {
            parents_[x] = x;
            count_++;
        }
        bool isValid(int x) {
            return parents_[x] >= 0;
        }
        int getCount() {
            return count_;
        }

        int find(int x) {
            int parent = x;
            while (parents_[parent] != parent) {
                parent = parents_[parent];
            }

            while (x != parent) {
                int tmp = parents_[x];
                parents_[x] = parent;
                x = tmp;
            }
            return parent;
        }
    };

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        UnionFind union_find(m * n);
        vector<int> ans;
        for (const auto position : positions) {
            int row = position[0];
            int col = position[1];
            int index = position[0] * n + position[1];
            if (union_find.isValid(index)) {
                ans.push_back(union_find.getCount());
                continue;
            }
            vector<int> neighbors;
            for (const auto& direct : directions) {
                int new_row = row + direct.first;
                int new_col = col + direct.second;
                int new_index = new_row * n + new_col;
                if (new_row < 0 || new_row >= m || new_col < 0 || new_col >= n) {
                    continue;
                }
                if (!union_find.isValid(new_index)) {
                    continue;
                }
                neighbors.push_back(new_index);
            }
            union_find.setParent(index);
            for (int neighbor : neighbors) {
                union_find.makeUnion(neighbor, index);                
            }
            ans.push_back(union_find.getCount());
        }
        return ans;
    }
};