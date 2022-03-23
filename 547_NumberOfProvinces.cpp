class Solution {
public:
    class UnionFind {
    private:
        int count_;
        vector<int> parents_;
    public:
        UnionFind(int n) : count_(n), parents_(vector<int>(n)) {
            for (int i = 0; i < n; i++) {
                parents_[i] = i;
            }
        }
        void makeUnion(int a, int b) {
            int root_a = find(a);
            int root_b = find(b);
            if (root_a == root_b)
                return;
            parents_[root_a] = root_b;
            count_--;
        }

        int find(int x) {
            int parent = x;
            while (parents_[parent] != parent)
                parent = parents_[parent];
            while (x != parent) {
                int tmp = parents_[x];
                parents_[x] = parent;
                x = tmp;
            }
            return parent;
        }
        int getCount() {
            return count_;
        }
    };

    int findCircleNum(vector<vector<int>>& isConnected) {
        int length = static_cast<int>(isConnected.size());
        UnionFind union_find(length);

        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if (!isConnected[i][j])
                    continue;
                union_find.makeUnion(i, j);
            }
        }
        return union_find.getCount();
    }
};