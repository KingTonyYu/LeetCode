class Solution {
public:
    string convert(string s, int numRows) {
        size_t length = s.size();
        size_t i_max = static_cast<size_t>(numRows);
        if (numRows == 1)
            return s;
        string ans;
        for (size_t i = 0; i < i_max; i++)
        {
            int interval_param = 0;
            size_t j = i;
            while (j < length)
            {
                ans.push_back(s[j]);
                size_t interval_index = interval_param == 0 ? 2 * (i_max - i) - 2 : 2 * i;
                interval_param = 1 - interval_param;
                if (interval_index == 0)
                {
                   interval_index = interval_param == 0 ? 2 * (i_max - i) - 2 : 2 * i; 
                    interval_param = 1 - interval_param;
                }
                j += interval_index;
            }
        }
        return ans;
    }
};
