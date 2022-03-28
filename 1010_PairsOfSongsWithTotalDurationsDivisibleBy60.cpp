class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        const int length = static_cast<int>(time.size());
        int ans = 0;

        vector<int> dictionary(61, 0);
        for (int i = 0; i < length; i++) {
            int tmp = time[i] % 60;
            ans += dictionary[(60 - tmp) % 60];
            dictionary[tmp] += 1;
        }
        return ans;
    }
};