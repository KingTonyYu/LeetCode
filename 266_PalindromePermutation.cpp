class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> hash(26);
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