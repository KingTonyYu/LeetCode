class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> digit_letter_table = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}
        };
        if (digits.empty())
            return {};

        vector<vector<char>> vector_set;
        vector<string> result{""};
        for (const auto& digit : digits) {
            vector_set.push_back(digit_letter_table[digit]);
        }
        for (const auto& letter_vector : vector_set) {
            vector<string> tmp;
            for (const auto& cur_result : result) {
                for (const auto& letter : letter_vector) {
                    tmp.push_back(cur_result + letter);
                }
            }
            swap(tmp, result);
        }
        return result;

    }
};