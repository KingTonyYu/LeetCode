class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        unordered_map<string, vector<string>> parents;
        if (!words.count(endWord))
            return {};
        int word_length = static_cast<int>(beginWord.size());
        queue<string> queue;
        unordered_map<string, int> steps;
        int step = 1;
        queue.push(beginWord);
        steps[beginWord] = 0;
        bool found_path = false;
        while(!queue.empty()) {
            int length = static_cast<int>(queue.size());
            for (int k = 0; k < length; k++) {
                string parent = queue.front();
                string word{parent};
                queue.pop();
                for (int i = 0; i < word_length; i++) {
                    char origin = word[i];
                    for (int j = 'a'; j <= 'z'; j++) {
                        if (origin == j)
                            continue;
                        word[i] = j;

                        if (word == endWord) {
                            found_path = true;
                        }
                        if (steps.count(word) && step == steps[word])
                            parents[word].push_back(parent);

                        if (!words.count(word))
                            continue;
                        parents[word].push_back(parent);
                        queue.push(word);
                        words.erase(word);
                        steps[word] = step;
                    }
                    word[i] = origin;
                }
            }
            if (found_path) {
                vector<vector<string>> ans;
                vector<string> cur_list;
                generatePath(endWord, cur_list, ans, parents, beginWord);
                return ans;
            }
            step++;
        }
        return {};
    }

    void generatePath(const string& word, vector<string>& cur_list, vector<vector<string>>& ans, const unordered_map<string, vector<string>>& parents, const string& begin_word) {
        if (word == begin_word) {
            cur_list.push_back(word);
            vector<string> tmp(cur_list.rbegin(), cur_list.rend());
            ans.push_back(tmp);
            cur_list.pop_back();
            return;
        }

        for (const string& parent : parents.at(word)) {
            cur_list.push_back(word);
            generatePath(parent, cur_list, ans, parents, begin_word);
            cur_list.pop_back();
        }
    }
};