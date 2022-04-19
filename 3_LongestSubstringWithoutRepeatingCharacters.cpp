class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = static_cast<int>(s.size());
        vector<int> window(256);
        int left = 0;
        int right = 0;
        int res = 0;
        while (right < length) {
            char c = s[right];
            window[c]++;
            right++;

            while(window[c] > 1) {
                char d = s[left];
                window[d]--;
                left++;
            }
            res = max(right - left, res);
        }
        return res;
    }
};