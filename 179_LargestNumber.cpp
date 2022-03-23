class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> nums_str;
        for (const auto num : nums)
            nums_str.push_back(to_string(num));

        sort(nums_str.begin(), nums_str.end(), [](const auto s1, const auto s2) {
            return s1 + s2 > s2 + s1;
        });

        if (nums_str[0] == "0") {
            return "0";
        }
        string result;
        for (const auto num : nums_str)
            result += num;
        return result;
    }
};