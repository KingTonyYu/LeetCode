class Trie {
public:
    Trie() {
        root_ = new TreeNode();
    }

    void insert(string word) {
        TreeNode* cur_node = root_;
        for (char c : word) {
            int loc = c - 'a';
            if (!cur_node->children[loc]) {
                cur_node->children[loc] = new TreeNode();
            }
            cur_node = cur_node->children[loc];
        }
        cur_node->is_word = true;
    }

    bool search(string word) {
        TreeNode* cur_node = root_;
        for (char c : word) {
            int loc = c - 'a';
            if (!cur_node->children[loc])
                return false;
            cur_node = cur_node->children[loc];
        }
        return cur_node->is_word;
    }

    bool startsWith(string prefix) {
        TreeNode* cur_node = root_;
        for (char c : prefix) {
            int loc = c - 'a';
            if (!cur_node->children[loc])
                return false;
            cur_node = cur_node->children[loc];
        }
        return true;
    }

private:
    struct TreeNode {
        bool is_word;
        vector<TreeNode* > children;
        TreeNode() : is_word(false), children(26, nullptr) {}
        ~TreeNode() {
            for (auto& child : children) {
                if (child)
                    delete child;
            }
        }
    };

    TreeNode* root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */