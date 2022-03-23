class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode root;
        for (const auto& word : words) {
            TrieNode* cur_node = &root;
            for (char c : word) {
                int loc = c - 'a';
                if (!cur_node->children[loc])
                    cur_node->children[loc] = new TrieNode();
                cur_node = cur_node->children[loc];
            }
            cur_node->word = new string(word);
        }

        vector<string> ans;
        int height = static_cast<int>(board.size());
        int width = static_cast<int>(board[0].size());   

        function<void(int, int, TrieNode*)> dfs_helper = [&](int i, int j, TrieNode* cur_node) {
            if (i < 0 || i >= height || j < 0 || j >= width || board[i][j] == '#')
                return;

            int loc = board[i][j] - 'a';

            if (!cur_node->children[loc])
                return;

            TrieNode* next_node = cur_node->children[loc];
            if (next_node->word) {
                ans.push_back(*next_node->word);
                delete next_node->word;
                next_node->word = nullptr;
            }

            cur_node = next_node;
            char cur_letter = board[i][j];
            board[i][j] = '#';
            dfs_helper(i + 1, j, cur_node);
            dfs_helper(i - 1, j, cur_node);
            dfs_helper(i, j + 1, cur_node);
            dfs_helper(i, j - 1, cur_node);
            board[i][j] = cur_letter;
        };

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                dfs_helper(i, j, &root);
            }
        }
        return ans;

    }

private:
    struct TrieNode {
        vector<TrieNode* > children;
        string* word;
        TrieNode() : children(vector<TrieNode* >(26)), word(nullptr) {}
        ~TrieNode() {
            for (auto& child : children) {
                delete child;
            }
        }
    };
};