class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<int> hash(26);
        vector<string> ans;
        if (!canPermutePalindrome(s, hash))
            return ans;
        char single_letter = ' ';
        size_t total_num = 0;
        for (int i = 0; i < 26; i++) {
            if (hash[i] % 2 == 1) {
                single_letter = i + 'a';
                hash[i]--;
            }
            hash[i] /= 2;
            total_num += hash[i];
        }

        string cur_str;
        permutation(cur_str, ans, hash, total_num);
        return postProcess(ans, single_letter);
    }
    vector<string> postProcess(vector<string> ans, char single_letter) {
        if (ans.empty())
            return {"" + single_letter};
        int half_length = ans[0].size() / 2;
        int length = ans[0].size();
        for (auto& str : ans) {
            string tmp = str;
            for (int i = 0; i < half_length; i++) {
                swap(tmp[i], tmp[length - i - 1]);
            }
            if (single_letter == ' ')
                str += tmp;
            else
                str += single_letter + tmp;
        }
        return ans;
    }

    void permutation(string& cur_str, vector<string>& ans, vector<int>& hash, const int total_num) {
        if (cur_str.size() == total_num) {
            ans.push_back(cur_str);
            return;
        }
        for (int i = 0; i < 26; i++) {
            if (hash[i] == 0)
                continue;
            cur_str.push_back(i + 'a');
            hash[i]--;
            permutation(cur_str, ans, hash, total_num);
            hash[i]++;
            cur_str.pop_back();
        }
    }

    bool canPermutePalindrome(string& s, vector<int>& hash) {

        for (char c : s) {
            hash[c - 'a']++;
        }
        int count = 0;
        for (const int& i : hash) {
            count += i % 2;
        }
        return count <= 1;
    }
};