class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord))
            return 0;
        int word_length = static_cast<int>(beginWord.size());
        queue<string> queue;
        queue.push(beginWord);
        int step = 1;
        while(!queue.empty()) {
            int length = static_cast<int>(queue.size());
            for (int k = 0; k < length; k++) {
                string word = queue.front();
                queue.pop();
                for (int i = 0; i < word_length; i++) {
                    char origin = word[i];
                    for (int j = 'a'; j <= 'z'; j++) {
                        word[i] = j;
                        if (word == endWord)
                            return step + 1;
                        if (words.count(word)) {
                            queue.push(word);
                            words.erase(word);
                        }
                    }
                    word[i] = origin;
                }
            }
            step++;
        }
        return 0;
    }
};